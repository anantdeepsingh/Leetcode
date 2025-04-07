class Solution {
private:
    int f(int ind,int target,vector<int>&nums,vector<vector<int>> &dp){
        if(target==0) return true;
        if(ind==0) return nums[0]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool ntake=f(ind-1,target,nums,dp);
        bool take=false;
        if(target>=nums[ind]){
            take=f(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=(take|ntake);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
       
        for(int x=0;x<n;x++){
            s+=nums[x];
        }
        if(s%2!=0) return false;
        int k=s/2;
        vector<vector<bool>>dp(n,vector<bool>(k+1,0));
        vector<bool>prev(k+1,0),curr(k+1,0);
        prev[0]=true,curr[0]=true;
       if(nums[0]<=k) prev[nums[0]]=true;
       for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
                bool ntake=prev[target];
                bool take=false;
                if(target>=nums[ind]){
                    take=prev[target-nums[ind]];
                }
                curr[target]=(take|ntake);
        }
        prev=curr;
       }
       return prev[k];
    }
};