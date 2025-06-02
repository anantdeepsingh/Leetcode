class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=*max_element(nums.begin(),nums.end());
        if(maxi<0){
            return maxi;
        }
        maxi=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};