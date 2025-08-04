const int mod=1e9+7;
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int n = min(arrLen, steps + 1);
        vector<vector<long long>>dp(n+1,vector<long long>(steps+1,0));
        dp[0][0]=1ll;




        for(int s=1;s<=steps;s++){
            for(int i=n-1;i>=0;i--){
                long long op1=0,op2=0,op3=0;
                if(i+1<=n-1) op1=dp[i+1][s-1]%mod;
                if(i<=n-1) op2=dp[i][s-1]%mod;
                if(i-1>=0) op3=dp[i-1][s-1]%mod;
                dp[i][s]=(1ll*op1%mod+op2%mod+op3%mod)%mod;
            }    
        }
       

        return dp[0][steps];
    }
};
