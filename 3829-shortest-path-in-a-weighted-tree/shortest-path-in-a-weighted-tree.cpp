#define pi pair<long long,int>

class ST {
public:
    vector<long long> st, lazy;

    ST(int n) {
        st.resize(4 * n);
        lazy.resize(4 * n);
    }

    void build(int ind, int low, int high, vector<long long>& arr) {
        if (low == high) {
            st[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        st[ind] = st[2 * ind + 1] + st[2 * ind + 2];
    }

    void push(int ind, int low, int high) {
        if (lazy[ind] != 0) {
            st[ind] += (high - low + 1LL) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
    }

    void update(int ind, int low, int high, int l, int r, long long val) {
        push(ind, low, high);
        if (high < l || low > r) return;
        if (low >= l && high <= r) {
            lazy[ind] += val;
            push(ind, low, high);
            return;
        }
        int mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        st[ind] = st[2 * ind + 1] + st[2 * ind + 2];
    }

    long long query(int ind, int low, int high, int l, int r) {
        push(ind, low, high);
        if (high < l || low > r) return 0;
        if (low >= l && high <= r) return st[ind];
        int mid = (low + high) / 2;
        long long left = query(2 * ind + 1, low, mid, l, r);
        long long right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

class Solution {
public:
    void dfs(int node, int par, vector<vector<pair<int, int>>>& adj, vector<int>& euler) {
        euler.push_back(node);
        for (auto& it : adj[node]) {
            int nnode = it.first;
            if (nnode == par) continue;
            dfs(nnode, node, adj, euler);
        }
        euler.push_back(node);
    }

    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        map<pair<int, int>, int> mp;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
            mp[{u, v}] = w;
            mp[{v, u}] = w;
        }

        vector<long long> dist(n + 1, 1e18);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 1});
        dist[1] = 0;

        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist[node]) continue;
            for (auto& [nnode, w] : adj[node]) {
                if (dist[node] + w < dist[nnode]) {
                    dist[nnode] = dist[node] + w;
                    pq.push({dist[nnode], nnode});
                }
            }
        }

        vector<int> euler;
        dfs(1, -1, adj, euler);

        int k = euler.size();
        vector<long long> v(k);
        map<int, int> st, ed;

        for (int i = 0; i < k; i++) {
            if (!st.count(euler[i])) st[euler[i]] = i;
            v[i] = dist[euler[i]];
        }
        for (int i = k - 1; i >= 0; i--) {
            if (!ed.count(euler[i])) ed[euler[i]] = i;
        }

        ST seg(k);
        seg.build(0, 0, k - 1, v);

        vector<int> ans;
        for (auto& it : queries) {
            if (it[0] == 1) {
                int u = it[1], v = it[2], nwt = it[3];
                int old = mp[{u, v}];
                long long change = 1LL * nwt - old;

                int start = (st[u] > st[v]) ? st[u] : st[v];
                int end = (st[u] > st[v]) ? ed[u] : ed[v];

                seg.update(0, 0, k - 1, start, end, change);
                mp[{u, v}] = mp[{v, u}] = nwt;
            } else {
                int u = it[1];
                ans.push_back(seg.query(0, 0, k - 1, st[u], st[u]));
            }
        }
        return ans;
    }
};
