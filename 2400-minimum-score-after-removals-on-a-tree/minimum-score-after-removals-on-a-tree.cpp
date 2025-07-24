class Solution {
public:
    vector<int>parent,sub,tin,tout;
    int timer=0;
    int dfs(int node,int par,vector<vector<int>>&adj,vector<int>&nums){
        int val=nums[node];
        parent[node]=par;
        tin[node]=++timer;
        for(auto &it:adj[node]){
            if(it==par) continue;
            val^=dfs(it,node,adj,nums);
        }
        sub[node]=val;
        tout[node]=++timer;
        return val;
    }

    bool isAncestor(int a,int b){
        return tin[a]<=tin[b] && tout[a]>=tout[b];
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        parent.resize(n);
        sub.resize(n);
        tin.resize(n);
        tout.resize(n);
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,adj,nums);
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum^nums[i];
        }
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int a=(parent[u]==v)?u:v; // checkinng who is the child either u or v 
            for(int j=i+1;j<n-1;j++){
                int k=edges[j][0];
                int l=edges[j][1];
                int b=parent[k]==l?k:l;  // checkinng who is the child either of k or l

                if(isAncestor(a,b)){
                    // a is ancestor of b
                    int s1=sub[b];
                    int s2=sub[a]^sub[b];
                    int s3=sum^sub[a];

                    int mx=max({s1,s2,s3});
                    int mn=min({s1,s2,s3});
                    ans=min(ans,mx-mn);
                }
                else if(isAncestor(b,a)){

                    //  b is ancestor of a
                    int s1=sub[a];
                    int s2=sub[b]^sub[a];
                    int s3=sum^sub[b];

                    int mx=max({s1,s2,s3});
                    int mn=min({s1,s2,s3});
                    ans=min(ans,mx-mn);
                }
                else{
                    // independent 
                    int s1=sub[a];
                    int s2=sub[b];
                    int s3=sum^s1^s2;

                    int mx=max({s1,s2,s3});
                    int mn=min({s1,s2,s3});
                    ans=min(ans,mx-mn);
                }
            }
        }

        return ans;
    }
};