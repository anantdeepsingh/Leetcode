const int mod=1e9+7;
class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int target,int pow){
        if(target==0) return 1;
        if(i>target) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        int op1=solve(i+1,target,pow)%mod;
        int op2=0;
        long long val=1;
        for(int j=0;j<pow;j++){
            val=((val%mod)*(i%mod))%mod;
        }
        if(val<=target){
            op2=solve(i+1,target-val,pow)%mod;
        }
        return dp[i][target]=(op1+op2)%mod;
    }
    int numberOfWays(int n, int x) {
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(1,n,x);
    }
};
