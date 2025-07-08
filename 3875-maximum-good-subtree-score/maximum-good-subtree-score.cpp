const int mod = 1e9 + 7;

class Solution {
public:
    int score;
    vector<vector<int>> dp;

    unordered_map<string, int> subtreeCache; // memoization

    // Hash function to convert vals vector to string key
    string hashVec(const vector<int>& vals) {
        string s;
        for (int v : vals) {
            s += to_string(v) + ",";
        }
        return s;
    }

    int getNewMask(int val, int mask) {
        int newmask = mask;
        int digitSeen = 0;
        while (val > 0) {
            int rem = val % 10;
            if ((newmask >> rem) & 1 || (digitSeen >> rem) & 1) {
                return -1;
            }
            digitSeen |= (1 << rem);
            newmask |= (1 << rem);
            val /= 10;
        }
        return newmask;
    }

    int f(int i, int mask, vector<int>& vals) {
        if (mask == (1 << 10) - 1) return 0;
        if (i == vals.size()) return 0;
        if (dp[i][mask] != -1) return dp[i][mask];

        int op1 = f(i + 1, mask, vals);
        int op2 = 0;

        int newmask = getNewMask(vals[i], mask);
        if (newmask != -1) {
            op2 = (vals[i] + f(i + 1, newmask, vals)) % mod;
        }

        return dp[i][mask] = max(op1, op2);
    }

    vector<int> dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vals) {
        vector<int> subnodes;
        for (auto & neighbor : adj[node]) {
            if (neighbor == parent) continue;
            vector<int> childVals = dfs(neighbor, node, adj, vals);
            subnodes.insert(subnodes.end(), childVals.begin(), childVals.end());
        }

        subnodes.push_back(vals[node]);
        sort(subnodes.begin(), subnodes.end());  // Normalize for hashing

        string key = hashVec(subnodes);
        if (subtreeCache.count(key)) {
            score = (score + subtreeCache[key]) % mod;
        } else {
            int m = subnodes.size();
            for (int i = 0; i <= m; i++) {
                fill(dp[i].begin(), dp[i].end(), -1);
            }

            int val = f(0, 0, subnodes) % mod;
            subtreeCache[key] = val;
            score = (score + val) % mod;
        }

        return subnodes;
    }

    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int n = vals.size();
        score = 0;

        dp.assign(n + 1, vector<int>(1 << 10, -1));

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (par[i] == -1) continue;
            adj[i].push_back(par[i]);
            adj[par[i]].push_back(i);
        }

        dfs(0, -1, adj, vals);
        return score;
    }
};
