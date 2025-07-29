class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(auto &it:graph[i]){
                adj[i].push_back(it);
            }
        }

        vector<int>color(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto &it:adj[node]){
                        if(color[it]==-1){
                            color[it]=!color[node];
                            q.push(it);
                        }
                        else if(color[it]==color[node]){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};