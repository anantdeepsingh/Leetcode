#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        ll total=(1ll*n*(n+1))/2;
        int maxi=*max_element(nums.begin(),nums.end());
        ll lessK=0ll;
        int cnt=0;
        int l=0,r=0;
        while(r<n){
            if(nums[r]==maxi){
                cnt++;
            }
            while(cnt>=k){
                if(nums[l]==maxi){
                    cnt--;
                }
                l++;
            }
            if(cnt<k){
                lessK+=1ll*(r-l+1);
            }
            r++;
        }
        return total-lessK;
    }
};