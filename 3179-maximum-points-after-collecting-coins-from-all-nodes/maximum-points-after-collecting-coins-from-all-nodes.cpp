class Solution {
public:
    vector<int> c;
    vector<vector<int>> adj;
    vector<vector<int>> dp;
    int K;

    int dfs(int node, int par, int lev) {
        if(lev>40) return 0;
        if (dp[node][lev] != -1) return dp[node][lev];

        double fac = pow(0.5, lev);
        int normal = floor(c[node] * fac) - K;   // safer flooring
        int special = floor((c[node] * fac) / 2.0);

        for (auto &child : adj[node]) {
            if (child == par) continue;

            int op1 = dfs(child, node, lev);
            int op2=0;
            if(lev<40) op2 = dfs(child, node, lev + 1);

            normal += max(op1, op2);
            special += dfs(child, node, lev + 1);
        }

        return dp[node][lev] = max(normal, special);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        // if (k >= 14) return 0;

        int n = coins.size();
        adj.resize(n);
        c = coins;
        K = k;

        for (auto &it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dp.assign(n, vector<int>(41, -1)); // safe cap

        return dfs(0, -1, 0);
    }
};
