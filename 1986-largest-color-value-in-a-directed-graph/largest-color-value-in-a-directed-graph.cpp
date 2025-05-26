class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        // contains cycle or not 
        map<int,int>par;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
            par[v]=u;
        }

        
        queue<int>q;
        vector<vector<int>>dp(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                // dp[i][colors[i]-'a']++;
                q.push(i);
            }
        }
        int cnt=0;
        int root;
        while(!q.empty()){
            int node=q.front();
            root=node;
            q.pop();
            cnt++;
            dp[node][colors[node]-'a']++;
            for(auto it:adj[node]){
                for(int i=0;i<26;i++){
                    dp[it][i]=max(dp[it][i],dp[node][i]);
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(cnt!=n) return -1;

        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                maxi=max(maxi,dp[i][j]);
            }
            // cout<<endl;
        }

        return maxi;

    }
};