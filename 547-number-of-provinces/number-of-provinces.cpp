class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(auto &neighbor:adj[node]){
            if(!vis[neighbor]){
                dfs(neighbor,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int>vis(n,0);
        int components=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                components++;
                dfs(i,adj,vis);
            }
        }

        return components;
    }
};