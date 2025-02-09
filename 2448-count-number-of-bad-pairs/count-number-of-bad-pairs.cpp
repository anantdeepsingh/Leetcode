#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll n=nums.size();
        map<ll,ll>mp;
        ll res=0;
        for(ll i=0;i<n;i++){
            ll val=1ll*nums[i]-i;
            if(mp.find(val)!=mp.end()){
                res+=mp[val];
            }
            mp[val]++;
        }
        ll tcnt=(n*(n-1))/2;
        return tcnt-res;
    }
};