class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, set<string> &st, vector<vector<string>> &accounts) {
    vis[node] = 1;
    int m = accounts[node].size();
    for (int i = 1; i < m; i++) {
        st.insert(accounts[node][i]);
    }
    for (auto it : adj[node]) {
        if (!vis[it]) dfs(it, adj, vis, st, accounts);
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    map<string, int> mp;
    int n = accounts.size();
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        int m = accounts[i].size();
        for (int j = 1; j < m; j++) {
            if (mp.count(accounts[i][j])) {
                int node = mp[accounts[i][j]];
                adj[i].push_back(node);
                adj[node].push_back(i);
            } else {
                mp[accounts[i][j]] = i;
            }
        }
    }

    vector<vector<string>> res;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            set<string> st;
            dfs(i, adj, vis, st, accounts);

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : st) {
                temp.push_back(it);
            }
            res.push_back(temp);
        }
    }

    return res;
}
};