class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        int maxi=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(maxi>nums[i]){
                ans=max(ans,maxi-nums[i]);
            }
            else{
                maxi=max(maxi,nums[i]);
            }
        }
        return ans==INT_MIN?-1:ans;
    }
};