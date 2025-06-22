class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void f(int node,vector<int>adj[],vector<int>path){
        if(node==n-1){
            path.push_back(n-1);
            ans.push_back(path);
            return;
        }

        for(auto adjNode:adj[node]){
            path.push_back(node);
            f(adjNode,adj,path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vector<int>path;
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto nodes:graph[i]){
                adj[i].push_back(nodes);
            }
        }

        f(0,adj,path);
        return ans;
    }
};

// O(E)=no of edges
// 