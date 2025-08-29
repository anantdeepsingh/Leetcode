class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
       int low=0,high=n-1;
       int ans=-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=mid;
            break;
        }
        else if(nums[low]<=nums[mid]){
            if(target>=nums[low] && target<=nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(target>=nums[mid] && target<=nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
       }

       return ans;
    }
};

/*


[1,3]

0 1 

low=0,high=1
mid=0;



*/