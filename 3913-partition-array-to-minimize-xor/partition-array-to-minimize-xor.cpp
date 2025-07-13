class Solution {
public:
    int dp[251][251];
    int f(int i,int k,vector<int>&nums,vector<int>&pre){
        int n=nums.size();
        if(k<0) return INT_MAX;
        if(i==n){
            if(k==0) return 0;
            return INT_MAX;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int ans=INT_MAX;
        for(int j=i;j<n;j++){
            if(i==0){
                ans=min(ans,max(pre[j],f(j+1,k-1,nums,pre)));
            }
            else{
                ans=min(ans,max(pre[j]^pre[i-1],f(j+1,k-1,nums,pre)));
            }
        }
        return dp[i][k]=ans;
    }
    int minXor(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]^nums[i];
        }
        memset(dp,-1,sizeof(dp));
        return f(0,k,nums,pre);
    }
};