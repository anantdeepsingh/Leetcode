#define ll long long
class Solution {
public:
    int n;
    ll solve(int ind,vector<vector<int>>& questions,vector<ll>&dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        ll npick=solve(ind+1,questions,dp);
        ll pick=0;
        pick=1ll*questions[ind][0]+1ll*solve(ind+questions[ind][1]+1,questions,dp);
        return dp[ind]=max(1ll*npick,1ll*pick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        vector<ll>dp(n+1,-1ll);
        return solve(0,questions,dp);
    }
};