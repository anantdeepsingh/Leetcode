class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto &v:graph[i]){
                adj[v].push_back(i);
                indegree[i]++;
            }
        }

        // O(E)
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // O(V)
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        // O(V)
        sort(ans.begin(),ans.end()); //O(VlogV)
        return ans;
    }
};

// time complexity: O(VlogV)
// space complexity:O(3*V)