class Solution {
public:
    bool isPossible(int divisor,vector<int>&nums,int threshold){
        int sum=0;
        for(auto &it:nums){
            if(it%divisor==0){
                sum+=it/divisor;
            }
            else{
                sum+=(it/divisor+1);
            }
        }

        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx=*max_element(nums.begin(),nums.end());
        int low=1,high=mx;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,nums,threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};

// tc: O(n)+O(nlogn)
// sc: O(1)