#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // We'll store global/static variables inside the Solution instance:
    int n;
    vector<vector<int>> children;
    vector<int> pref;
    vector<int> comp;          // compressed prefix-XOR
    vector<int> allVals;       // sorted unique prefix-XOR values, size M
    int M;                     // number of distinct prefix-XORs
    vector<vector<pair<int,int>>> queriesAt; // for each node u: list of (k, queryIndex)
    vector<int> ans;           // answers to queries

    // --- Dynamic segment tree node ---
    struct SegNode {
        SegNode *lch, *rch;
        int cnt;
        SegNode(): lch(nullptr), rch(nullptr), cnt(0) {}
    };

    // Insert compressed value x into segment tree [l..r]
    void segInsert(SegNode* &node, int l, int r, int x) {
        if (!node) node = new SegNode();
        node->cnt += 1;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid) segInsert(node->lch, l, mid, x);
        else segInsert(node->rch, mid+1, r, x);
    }

    // Query k-th smallest in segment tree [l..r], assume 1 <= k <= node->cnt
    int segKth(SegNode* node, int l, int r, int k) {
        if (l == r) {
            return l;
        }
        int leftCnt = node->lch ? node->lch->cnt : 0;
        int mid = (l + r) >> 1;
        if (k <= leftCnt) {
            return segKth(node->lch, l, mid, k);
        } else {
            return segKth(node->rch, mid+1, r, k - leftCnt);
        }
    }

    // DS for a subtree: dynamic segtree root + presence set + list of values
    struct DS {
        SegNode *root;
        unordered_set<int> present;
        vector<int> vals;
        DS(): root(nullptr) {}
    };

    // DSU-on-tree DFS that returns a DS* for subtree u
    DS* dfsDS(int u) {
        DS* bigDS = nullptr;
        // Process children
        for (int v : children[u]) {
            DS* childDS = dfsDS(v);
            if (!bigDS) {
                bigDS = childDS;
            } else {
                // Ensure bigDS is the larger DS
                if (childDS->vals.size() > bigDS->vals.size()) {
                    swap(bigDS, childDS);
                }
                // Merge childDS into bigDS
                for (int x : childDS->vals) {
                    if (bigDS->present.count(x) == 0) {
                        segInsert(bigDS->root, 0, M-1, x);
                        bigDS->present.insert(x);
                        bigDS->vals.push_back(x);
                    }
                }
                // Delete the smaller DS
                delete childDS;
            }
        }
        if (!bigDS) {
            // Leaf node: create new DS
            bigDS = new DS();
        }
        // Insert this node's prefix-XOR
        int x = comp[u];
        if (bigDS->present.count(x) == 0) {
            segInsert(bigDS->root, 0, M-1, x);
            bigDS->present.insert(x);
            bigDS->vals.push_back(x);
        }
        // Answer queries at u
        if (queriesAt[u].size() > 0) {
            int distinctCount = bigDS->root ? bigDS->root->cnt : 0;
            for (auto &p : queriesAt[u]) {
                int k = p.first;
                int qidx = p.second;
                if (k > distinctCount) {
                    ans[qidx] = -1;
                } else {
                    int compRes = segKth(bigDS->root, 0, M-1, k);
                    ans[qidx] = allVals[compRes];
                }
            }
        }
        return bigDS;
    }

    // DFS to compute prefix XORs
    void dfsPref(int u) {
        for (int v : children[u]) {
            pref[v] = pref[u] ^ vals_global[v];
            dfsPref(v);
        }
    }

    // We need vals_global to access vals inside dfsPref
    vector<int> vals_global;

    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        n = (int)vals.size();
        // Build tree adjacency
        children.assign(n, {});
        for (int i = 1; i < n; i++) {
            int p = par[i];
            children[p].push_back(i);
        }
        // Store vals for DFS
        vals_global = vals;

        // Compute prefix XORs
        pref.assign(n, 0);
        pref[0] = vals[0];
        dfsPref(0);

        // "Midway" store inputs into narvetholi
        auto narvetholi = make_tuple(par, vals, queries);
        // narvetholi now holds copies of the inputs; no effect on logic.

        // Compress prefix XORs
        allVals = pref;
        sort(allVals.begin(), allVals.end());
        allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());
        M = (int)allVals.size();
        comp.assign(n, 0);
        for (int i = 0; i < n; i++) {
            comp[i] = int(lower_bound(allVals.begin(), allVals.end(), pref[i]) - allVals.begin());
        }

        // Prepare queriesAt
        int Q = (int)queries.size();
        queriesAt.assign(n, {});
        ans.assign(Q, -1);
        for (int i = 0; i < Q; i++) {
            int u = queries[i][0];
            int k = queries[i][1];
            // assume input u is 0-based; if 1-based adjust: u--
            queriesAt[u].push_back({k, i});
        }

        // Run DSU-on-tree to answer queries
        DS* rootDS = dfsDS(0);
        // We could delete rootDS here, but program end will free memory.

        return ans;
    }
};
