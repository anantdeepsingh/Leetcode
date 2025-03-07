class Solution {
public:
    void dfs(int node,set<int>&st,vector<vector<int>>&adj,vector<int>&nums){
        if(st.find(nums[node])!=st.end()) {
            st.erase(nums[node]);
        }
        for(auto it:adj[node]){
            int val=nums[it];
            if(st.find(val)!=st.end()){
                dfs(it,st,adj,nums);
            }
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n=nums.size();
        
        vector<int>ans(n,1);
        int ind=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                ind=i;
                break;
            }
        }
        if(ind==-1) return ans;
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i);
        }
        set<int>st;
        for(int i=1;i<=100001;i++){
            st.insert(i);
        }

        int currNode=ind;
        while(currNode!=-1){
            dfs(currNode,st,adj,nums);
            ans[currNode]=*st.begin();
            currNode=parents[currNode];
        }
        return ans;
    }
};