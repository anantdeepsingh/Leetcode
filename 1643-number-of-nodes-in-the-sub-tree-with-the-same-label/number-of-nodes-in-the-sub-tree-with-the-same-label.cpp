class Solution {
public:
    vector<int> ans;

    vector<int> dfs(int node, int par, vector<vector<int>>& adj, string& s) {
        vector<int> count(26, 0);
        for (int it : adj[node]) {
            if (it == par) continue;
            vector<int> t = dfs(it, node, adj, s);
            for (int i = 0; i < 26; i++) {
                count[i] += t[i];
            }
        }
        count[s[node] - 'a']++;
        ans[node] = count[s[node] - 'a'];
        return count;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.assign(n, 0);
        vector<vector<int>> adj(n); 

        for (auto &it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, adj, labels);
        return ans;
    }
};
