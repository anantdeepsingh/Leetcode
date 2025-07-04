class Solution {
public:
    int cnt=0;
    map<pair<int,int>,int>mp;
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(mp.count({node,it})){
                if(!vis[it]){
                    dfs(it,adj,vis);
                }
            }
            else{
                if(!vis[it]){
                    cnt++;
                    dfs(it,adj,vis);
                }
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            mp[{u,v}]++;
            adj[v].push_back(u);
        }

        vector<int>vis(n,0);

        dfs(0,adj,vis);

        return n-1-cnt;
    }
};