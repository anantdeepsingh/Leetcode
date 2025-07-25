class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=nums[n-1];
        if(sum<0) return sum;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<0) break;
            if(nums[i]==nums[i+1]) continue;
            else sum+=nums[i];
        }
        return sum;
    }
};