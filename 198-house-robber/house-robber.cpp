class Solution {
public:
    int n;
    vector<int>dp;
    int f(int i,vector<int>&nums){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int op1=f(i+1,nums);
        int op2=nums[i]+f(i+2,nums);
        return dp[i]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,-1);
        return f(0,nums);
    }
};