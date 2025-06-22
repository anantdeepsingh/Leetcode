class Solution {
public:
    bool containsCycle(int node,int par,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(containsCycle(it,node,adj,vis)) return true;
            }
            else{
                if(it!=par) return true;
            }
        }
        return false;
    }
    void dfs(int node,vector<int>adj[],vector<int>&choice,vector<int>&val,int ind,vector<int>&vis){
        vis[node]=1;
        val[node]=choice[ind];

        // cout<<node<<endl;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,choice,val,ind+1,vis);
            }
        }
    }
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        vector<int>vis(n,0);
        bool status =containsCycle(0,-1,adj,vis);
        vector<int>val(n,0);
        long long score=0ll;
        if(status){
            vector<int>choice(n,0);
            int j=0;
            for(int i=1;i<=n;i+=2){
                choice[j]=i;
                j++;
            }
            for(int i=n;i>=1;i--){
                if(i%2==0){
                    choice[j]=i;
                    j++;
                }
            }
            vector<int>v(n,0);
            int ind=0;
            dfs(0,adj,choice,val,0,v);
        }
        else{
            queue<int>q;
            for(int i=0;i<n;i++){
                if(indegree[i]==1){
                    q.push(i);
                }
            }
            int ind=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                val[node]=ind;
                for(auto it:adj[node]){
                    indegree[it]--;
                    if(indegree[it]==1){
                        q.push(it);
                    }
                }
                ind++;
            }
        }
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int v1=val[u];
            int v2=val[v];
            score=1ll*score+1ll*v1*v2;
        }
        return score;
    }
};