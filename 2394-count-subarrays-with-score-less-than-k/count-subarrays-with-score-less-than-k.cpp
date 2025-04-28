#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        int l=0,r=0;
        ll sum=0ll;
        ll cnt=0ll;
        while(r<n){
            sum+=1ll*nums[r];

            while(1ll*sum*(r-l+1)>=k){
                sum-=1ll*nums[l];
                l++;
            }
            if(1ll*sum*(r-l+1)<k){
                cnt+=1ll*(r-l+1);
            }
            r++;
        }
        return cnt;
    }
};