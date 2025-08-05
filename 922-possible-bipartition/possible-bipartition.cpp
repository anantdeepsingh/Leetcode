class Solution {
public:
    vector<int>vis;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n);
        for(auto &it:dislikes){
            int u=it[0];
            int v=it[1];
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
        vis.resize(n,-1);


        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                vis[i]=0;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    // cout<<node<<endl;
                    for(auto &it:adj[node]){
                        if(vis[it]==-1){
                            q.push(it);
                            vis[it]=!vis[node];
                        }
                        else if(vis[it]==vis[node]) return false;
                    }
                }
            
            }
        }


        return true;



    }
};

/*
if i am able to get cycle and cycle length is odd
*/