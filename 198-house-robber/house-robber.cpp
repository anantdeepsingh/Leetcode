class Solution {
public:
    int maxAmount(int ind,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int op1=maxAmount(ind+1,nums,dp);
        int op2=nums[ind]+maxAmount(ind+2,nums,dp);
        return dp[ind]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return maxAmount(0,nums,dp);
    }
};