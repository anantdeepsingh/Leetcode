class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>&nums){
        if(i==n) return 0;
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        int ntake=solve(i+1,j,nums);
        int take=0;
        if(j==-1 || nums[i]>nums[j]){
            take=1+solve(i+1,i,nums);
        } 
        return dp[i][j+1]=max(take,ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,vector<int>(n+1,-1));
        return solve(0,-1,nums);
    }
};