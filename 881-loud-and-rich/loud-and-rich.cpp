class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto &it:richer){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        vector<int>ans(n);
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                mp[i]++;
            }

            ans[i]=i;
        }

        vector<int>order;
        while(!q.empty()){
            int node=q.front();
            order.push_back(node);
            q.pop();
            for(auto &it:adj[node]){

                if(quiet[ans[node]]<quiet[ans[it]]) ans[it]=ans[node];
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        

        return ans;

    }
};