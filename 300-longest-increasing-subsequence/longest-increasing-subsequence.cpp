class Solution {
public:
    vector<vector<int>>dp;
    int maxLen(int ind,int prev,vector<int>&nums){
        int n=nums.size();
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int ans=0;
        ans=max(ans,maxLen(ind+1,prev,nums));
        if(prev==-1 || nums[ind]>nums[prev]){
            ans=max(ans,1+maxLen(ind+1,ind,nums));
        }
        return dp[ind][prev+1]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<int>(n,-1));
        return maxLen(0,-1,nums);
    }
};