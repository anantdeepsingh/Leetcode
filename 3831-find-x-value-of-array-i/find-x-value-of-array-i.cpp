#define ll long long 
class Solution {
public:

    long long solve(int ind,int prev,int rem,vector<int>&nums,vector<vector<ll>>&dp,int k){
        if(ind==nums.size()) return 0;
        ll op1=0ll;
        ll op2=0ll;
        ll score=0ll;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        if(prev==-1){
            op1=solve(ind+1,prev,rem,nums,dp,k);
            if(nums[ind]==rem){
                score++;
            }
            op2=score+solve(ind+1,nums[ind],rem,nums,dp,k);
        }
        else{
            int gap=(prev*nums[ind])%k;
            if(gap==rem){
                score++;
            }

            op2=score+solve(ind+1,gap,rem,nums,dp,k);
        }


        return dp[ind][prev+1]=op1+op2;
    }
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%k;
        }
        vector<ll>ans;
        for(int i=0;i<k;i++){
            vector<vector<ll>>dp(n+1,vector<ll>(k+1,-1));
            ans.push_back(solve(0,-1,i,nums,dp,k));
        }
        return ans;
    }
};