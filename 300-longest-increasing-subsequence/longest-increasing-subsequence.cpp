class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        res.push_back(nums[0]);
        for(int i=1;i<n;i++){
            int size=res.size();
            if(nums[i]>res[size-1]){
                res.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[ind]=nums[i];
            }
        }

        return (int)res.size();
    }
};