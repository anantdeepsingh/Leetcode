class Solution {
public:
    int countSubarrays(vector<int>&nums,int k){
        if(k<0) return 0;
        map<int,int>mp;
        int l=0,r=0;
        int n=nums.size();
        int ans=0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            if(mp.size()<=k){
                ans+=r-l+1;
            }
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarrays(nums,k)-countSubarrays(nums,k-1);
    }
};