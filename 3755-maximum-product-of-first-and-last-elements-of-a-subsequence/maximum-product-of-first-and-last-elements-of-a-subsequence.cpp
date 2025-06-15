#define ll long long
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        map<ll,int>mp;
        ll ans=LLONG_MIN;
        int ind=1;

        if(m==1){
            ll res=LLONG_MIN;
            for(int i=0;i<n;i++){
                res=max(res,1ll*nums[i]*nums[i]);
            }
            return res;
        }
        mp[nums[0]]++;
        for(int i=m-1;i<n;i++){
            auto it1=mp.begin();
            auto it2=mp.rbegin();
            ans=max(ans,1ll*(*it1).first*nums[i]);
            ans=max(ans,1ll*(*it2).first*nums[i]);
            mp[1ll*nums[ind]]++;
            ind++;
        }
        return ans;
    }
};
