class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=INT_MAX;
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            mini=min(mini,nums[mid]);
            if(nums[low]<=nums[mid]){
                // left part sorted
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return mini;
    }
};