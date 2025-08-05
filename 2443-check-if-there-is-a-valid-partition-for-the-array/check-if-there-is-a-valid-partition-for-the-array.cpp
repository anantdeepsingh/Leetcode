class Solution {
public:
    bool solve(int i,vector<int>& nums,vector<int>&dp){
        int n=nums.size();
        if(i>n) return  false;
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        bool flag=false;
        bool op1=false,op2=false,op3=false;
        if(i+1<=n-1 && nums[i]==nums[i+1]){
            op1=solve(i+2,nums,dp);
            flag=true;
        }
        if(i+2<=n-1 && nums[i]==nums[i+1] && nums[i]==nums[i+2]){
            op2=solve(i+3,nums,dp);
            flag=true;
        }
        if(i+2<=n-1 && nums[i+2]-nums[i+1]==1  && nums[i+1]-nums[i]==1){
            op3=solve(i+3,nums,dp);
            flag=true;
        }

        if(flag==false){
            return false;
        }

        return dp[i]=op1||op2||op3;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};


/*




*/