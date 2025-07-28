class Solution {
public:
    int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int cost =nums[ind]*nums[i-1]*nums[j+1]+f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
            maxi=max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        vector<int>arr;
        int n=nums.size();
        arr.push_back(1);
        for(auto it:nums){
            arr.push_back(it);
        }
        arr.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return f(1,nums.size(),arr,dp);
    }
};