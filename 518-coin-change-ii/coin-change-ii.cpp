class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int i,int amt,vector<int>&coins){
        if(amt==0) return 1;
        if(i==n) return 0;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int ans=0;
        ans+=solve(i+1,amt,coins);
        if(coins[i]<=amt){
            ans+=solve(i,amt-coins[i],coins);
        }

        return dp[i][amt]=ans;
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
};