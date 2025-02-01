class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%2;
        }

        for(int i=1;i<n;i++){
            if(nums[i]==0 && nums[i-1]==0 || nums[i]==1 && nums[i-1]==1) return false;
        }

        return true;
    }
};