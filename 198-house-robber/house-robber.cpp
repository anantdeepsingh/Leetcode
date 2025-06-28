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
        // return f(0,nums);
        int ans=0;
        dp[0]=nums[0];
        ans=max(ans,dp[0]);
        if(n>1){
            dp[1]=max(nums[0],nums[1]);
            ans=max(ans,dp[1]);
        }
        for(int i=2;i<n;i++){
           dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};