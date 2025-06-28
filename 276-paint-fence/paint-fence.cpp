class Solution {
public:
    int numWays(int n, int k) {
        vector<int>dp(n+1);
        dp[1]=k;
        if(n>1){
            dp[2]=k*k;
        }

        for(int i=3;i<=n;i++){
            dp[i]=(k-1)*(dp[i-1]+dp[i-2]);
        }

        return dp[n];
    }
};