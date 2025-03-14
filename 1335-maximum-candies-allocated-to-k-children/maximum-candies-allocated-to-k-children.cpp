#define ll long long
class Solution {
public:
    bool check(ll mid,vector<int>& candies, long long k){
        ll cnt=0;
        
        for(int i=0;i<candies.size();i++){
            cnt+=1ll*(candies[i]/mid);
        }
        return cnt>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        ll n=1ll*candies.size();
        ll low=1ll;
        ll high=1e12;
        ll ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(check(mid,candies,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
};