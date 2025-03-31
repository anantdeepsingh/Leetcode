class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]+nums[nums.size()-i-1]);
        }
        return maxi;
    }
};



//  3 5 4 2 4 6

//  2 3 4 4 5 6


//  2 3 3 5