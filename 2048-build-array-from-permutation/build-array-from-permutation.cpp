class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int i=0;
        for(auto it:nums){
            int ind=it;
            ans[i]=nums[ind];
            i++;
        }
        return ans;
    }
};