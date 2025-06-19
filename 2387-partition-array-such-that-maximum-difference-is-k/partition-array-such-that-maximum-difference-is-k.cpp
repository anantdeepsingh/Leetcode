class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int cnt=0;
        while(i<n){
            int ind=upper_bound(nums.begin(),nums.end(),nums[i]+k)-nums.begin();
            cnt++;
            i=ind;
        }
        return cnt;
    }
};