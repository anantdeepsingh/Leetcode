#define ll long long
class Solution {
public:
    ll n;
    bool check(ll mid,vector<int>&ranks,int cars){
        ll cnt=0;
        for(ll i=0;i<n;i++){
            ll val=mid/(ranks[i]);
            cnt+=sqrt(val);
        }
        return cnt>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        n=1ll*ranks.size();
        ll low=0,high=1e18;
        ll ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(check(mid,ranks,cars)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};