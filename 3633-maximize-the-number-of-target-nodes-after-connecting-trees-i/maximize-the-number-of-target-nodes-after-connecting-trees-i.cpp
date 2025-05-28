class Solution {
public:
    vector<vector<int>> compute(vector<vector<int>>adj,int n){
        vector<vector<int>>grid(n,vector<int>(1001,0));
        for(int i=0;i<n;i++){
            queue<int>q;
            q.push(i);
            vector<int>dist(n,1e8);
            dist[i]=0;
            vector<int>vis(n,0);
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        dist[it]=dist[node]+1;
                        q.push(it);
                    }
                }
            }


            sort(dist.begin(),dist.end());

            for(auto it:dist){
                grid[i][it]++;
            }

        }


        for(int i=0;i<n;i++){
            for(int j=1;j<=1000;j++){
                grid[i][j]+=grid[i][j-1];
            }
        }

        return grid;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int s1=edges1.size();
        int n=s1+1;
        int s2=edges2.size();
        int m=s2+1;

        vector<vector<int>>adj1(n),adj2(m);
        for(auto it:edges1){
            int u=it[0];
            int v=it[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto it:edges2){
            int u=it[0];
            int v=it[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<vector<int>>grid1=compute(adj1,n);
        vector<vector<int>>grid2=compute(adj2,m);


        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]+=grid1[i][k];

            int maxi=0;

            for(int j=0;j<m;j++){
                if(k>0){
                    maxi=max(maxi,grid2[j][k-1]);
                }
            }
            ans[i]+=maxi;

            cout<<grid1[i][k]<<" "<<maxi<<endl;
        }
        return ans;
    }
};