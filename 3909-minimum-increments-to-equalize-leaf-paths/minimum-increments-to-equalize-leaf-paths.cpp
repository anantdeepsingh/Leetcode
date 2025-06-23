class Solution {
public:
        long long changes=0;
        vector<int>cost;
       long long dfs(int node, int par,vector<vector<int>>&adj) {
        long long maxSum = 0;
        vector<long long> pathSums;
    
        for (auto it : adj[node]) {
            if (it == par) continue;
            long long subSum = dfs(it, node,adj);
            pathSums.push_back(subSum);
            maxSum = max(maxSum, subSum);
        }
        for (auto it : pathSums) {
            if (it < maxSum) changes++;
        }
    
        return 1ll*cost[node] + 1ll*maxSum;
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& _cost) {
        vector<vector<int>>adj(n);
        cost=_cost;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0,-1,adj);
        return (int)changes;
    }
};