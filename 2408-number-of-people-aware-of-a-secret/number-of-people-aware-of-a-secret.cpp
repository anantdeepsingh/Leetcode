const int mod=1e9+7;
class Solution {
public:
    vector<int>dp;
    int solve(int i,int forget,int delay){
        if(i<=0) return 0;
        if(i==1) return 1;
        if(dp[i]!=-1) return dp[i]%mod;
        int ans=0;
        for(int j=i-forget+1;j<=i-delay;j++){
            ans=(ans+solve(j,forget,delay))%mod;
        }

        return dp[i]=ans%mod;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans=0;
        dp.assign(n+1,-1);
        for(int i=n-forget+1;i<=n;i++){
            ans=(ans+solve(i,forget,delay))%mod;
        }
        return ans;
    }
};