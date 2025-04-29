#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll cnt=0ll;
        int n=nums.size();
        int l=0,r=0;
        ll total=(1ll*n*(n+1))/2;
        int maxi=*max_element(nums.begin(),nums.end());
        map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp[maxi]>=k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }

            if(mp[maxi]<k){
                cnt+=1ll*(r-l+1);
            }
            r++;
        }

        return total-cnt;
    }
};