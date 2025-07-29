class Solution {
public:
    vector<int>subNodes;
    vector<int>res;
    int sum=0;
    int dfs(int node,int par,vector<vector<int>>&adj){
        int cnt=0;
        for(auto &it:adj[node]){
            if(it==par) continue;
            cnt+=dfs(it,node,adj);
        }
        subNodes[node]=cnt+1;
        return cnt+1;
    }
    void dfs2(int node,int par,vector<vector<int>>&adj){
        for(auto &it:adj[node]){
            if(it==par) continue;
            res[it]=res[node]-subNodes[it]+(adj.size()-subNodes[it]);
            dfs2(it,node,adj);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        subNodes.resize(n,0);
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,adj);

        vector<int>dist(n,0);
        queue<int>q;
        vector<int>vis(n,0);
        int sum=0;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    dist[it]=dist[node]+1;
                    q.push(it);
                    sum+=dist[it];
                }
            }
        }

        res.resize(n);
        res[0]=sum;
        vector<int>ans;
        ans.push_back(sum);

        dfs2(0,-1,adj);
        return res;
    }
};