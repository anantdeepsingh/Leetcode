class Solution {
public:
    
    int countLevels(vector<vector<int>>& adj, int n, int start, bool countEven) {
        queue<int> q;
        vector<int> dist(n, -1);
        q.push(start);
        dist[start] = 0;

        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            if ((dist[node] % 2 == 0) == countEven) count++;

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj1(n), adj2(m);
        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        // Start nodes
        int node1 = 0;
        int node2 = !adj1[0].empty() ? adj1[0][0] : 0;

        
        int evenCount = countLevels(adj1, n, node1, true);
        int oddCount = countLevels(adj1, n, node2, true);

        // Only do BFS once on adj2
        int t = max(
            countLevels(adj2, m, node1, false),
            countLevels(adj2, m, adj2[node1].empty() ? node1 : adj2[node1][0], false)
        );

        vector<int> ans(n);
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [node, level] = q.front(); q.pop();

            ans[node] = (level % 2 == 0) ? (evenCount + t) : (oddCount + t);

            for (int neighbor : adj1[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, level + 1});
                }
            }
        }

        return ans;
    }
};
