const int mod=1e9+7;
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int n = min(arrLen, steps + 1);
        vector<long long>prev(steps+1,0),curr(steps+1,0);
        prev[0]=1;




        for(int s=1;s<=steps;s++){
            for(int i=n-1;i>=0;i--){
                long long op1=0,op2=0,op3=0;
                if(i+1<=n-1) op1=prev[i+1]%mod;
                if(i<=n-1) op2=prev[i]%mod;
                if(i-1>=0) op3=prev[i-1]%mod;
                curr[i]=(1ll*op1%mod+op2%mod+op3%mod)%mod;
            }    
            prev=curr;
        }
       

        return prev[0];
    }
};


/*

dp[i][s] => dp[i-1][s-1]
dp[i][s]=>dp[i+1][s+1]

*** * ***
*** * ***
*** * ***



*/