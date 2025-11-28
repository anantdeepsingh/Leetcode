class Solution {
public:
    pair<long long,long long> dfs(int node,int par,vector<vector<int>>&adj,vector<int>&values,int k){
        long long sum=0,cnt=0;
        for(auto &it:adj[node]){
            if(it==par) continue;
            pair<long long ,long long>t=dfs(it,node,adj,values,k);
            sum+=t.first;
            cnt+=t.second;
        }
        sum+=1ll*values[node];
        if(sum%k==0) return {0,cnt+1};
        return {sum,cnt};
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        pair<long long,long long>ans=dfs(0,-1,adj,values,k);
        return (int)ans.second;
    }
};