class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=n;
        nums[0]-=k;
        for(int i=1;i<n;i++){
            if(nums[i]+k<nums[i-1]+1){
                nums[i]=nums[i-1];
                res--;
            }
            else{
                nums[i]=max(nums[i-1]+1,nums[i]-k);
            }
        }
        return res;
    }
};