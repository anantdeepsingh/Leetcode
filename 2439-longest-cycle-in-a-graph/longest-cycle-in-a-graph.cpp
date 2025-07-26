class Solution {
public:
    int dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        int cnt=1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                cnt+=dfs(it,adj,vis);
            }
        }
        return cnt;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            int u=i;
            int v=edges[i];
            if(v==-1) continue;
            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int>vis(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=1;
            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]){
                cnt++;
            }
        }

        if(cnt==n) return -1; // no cycle
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                
                int len=dfs(i,adj,vis);

                ans=max(ans,len);
            }
        }

        return ans;
    }   
};