class Solution {
public:
    vector<int>tin,low,vis;
    vector<vector<int>>adj;
    int timer=1;
    vector<vector<int>>ans;
    void dfs(int node,int par){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto &it:adj[node]){
            if(it==par) continue;
            if(!vis[it]){
                dfs(it,node);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    ans.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       adj.resize(n);
        for(auto &it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.resize(n);
        low.resize(n);
        vis.resize(n,0);
        dfs(0,-1);
        return ans;
    }
};


// 


// 0 1 1
// 2 2 2
// 1 3 3 
// 3 4 4

// 
// checking 1->3 edge
// low[3]>tin[1]  4 > 3 means its a bridge

// 1->0 
// already viited 0 
// low[1]=min(low[1],low[0])
// low[1]=1

// 2->1
// low[2]=min(low[2],low[1]);
// low[2]=1

// low[1]>tin[2] 1 > 2 false not a bridge

// low[0]=1
// 0->2
// 1>1 false not a bridge
// only bridge 
// 1 3
