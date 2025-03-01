class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }

        vector<int>arr;
        for(auto it:nums){
            if(it!=0){
                arr.push_back(it);
            }
        }

        while(arr.size()<n){
            arr.push_back(0);
        }
        return arr;
    }
};