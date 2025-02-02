class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        for(int x=0;x<n-1;x++){
            if(nums[x]>nums[x+1]){
                ind=x;
                break;
            }
        }
        reverse(nums.begin(),nums.begin()+ind+1);
        reverse(nums.begin()+ind+1,nums.end());
        reverse(nums.begin(),nums.end());
        for(int x=0;x<n-1;x++){
            if(nums[x]>nums[x+1]){
                return false;
            }
        }
        return true;
    }
};