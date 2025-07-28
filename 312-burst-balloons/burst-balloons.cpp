class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>&nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=i;k<=j;k++){
            ans=max(ans,nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums)+solve(k+1,j,nums));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(1,n-2,nums);
    }
};