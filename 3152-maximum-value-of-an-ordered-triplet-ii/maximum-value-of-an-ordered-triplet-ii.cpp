#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n=nums.size();
        vector<ll>left(n,0ll);
        ll maxi=1ll*nums[0];
        for(int i=1;i<n-1;i++){
            left[i]=maxi;
            maxi=max(maxi,1ll*nums[i]);
        }
        vector<ll>right(n,0ll);
        maxi=1ll*nums[n-1];
        for(int i=n-2;i>=1;i--){
            right[i]=maxi;
            maxi=max(maxi,1ll*nums[i]);
        }


        ll ans=0;
        for(int i=1;i<n-1;i++){
            ans=max(ans,1ll*(left[i]-nums[i])*right[i]);
        }
        return ans;
    }
};