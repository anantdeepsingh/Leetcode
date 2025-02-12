#define ll long long 
class Solution {
public:
    ll n;
    ll dp[100010][2];
    ll solve(ll ind,ll toggle,vector<int>&nums){
        if(ind==n) return 0;
        if(dp[ind][toggle]!=-1) return dp[ind][toggle];
        ll op1=solve(ind+1,toggle,nums);
        ll op2=0;
        if(toggle==0){
            op2=1ll*nums[ind]+solve(ind+1,1,nums);
        }
        else{
            op2=-1ll*nums[ind]+solve(ind+1,0,nums);
        }

        return dp[ind][toggle]=max(op1,op2);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        // i will be taking up two states 1 for ind and the other one for toggling for even and odd index
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums);
    }
};