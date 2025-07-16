class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        
        int maxLen=0;
        vector<vector<int>>dp(k,vector<int>(k,0));
        int maxi=0;
        for(auto &it:nums){
            for(int i=0;i<k;i++){
                dp[it%k][i]=dp[i][it%k]+1;
                maxi=max(maxi,dp[it%k][i]);
            }
        }
        return maxi;
    }
};