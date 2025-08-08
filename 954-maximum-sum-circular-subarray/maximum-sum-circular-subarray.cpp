class Solution {
public:
    int maxSum(vector<int>&nums){
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        if(maxi<0) return maxi;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
    int minSum(vector<int>&nums){
        int n=nums.size();
        int mini=*min_element(nums.begin(),nums.end());
        if(mini>0) return mini;
        int sum=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>0){
                sum=0;
            }
            ans=min(ans,sum);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int tsum=accumulate(nums.begin(),nums.end(),0);
        int min_sum=minSum(nums);
        int max_sum=maxSum(nums);
        int maxi=*max_element(nums.begin(),nums.end());
        if(maxi<0) return maxi;
        return max(max_sum,tsum-min_sum);
    }
};