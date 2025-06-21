class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[n-1];
        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(maxi>nums[i]){
                ind=i;
                break;
            }
            maxi=max(maxi,nums[i]);
        }


        if(ind==-1){
            sort(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }

        reverse(nums.begin()+ind+1,nums.end());
    }
};