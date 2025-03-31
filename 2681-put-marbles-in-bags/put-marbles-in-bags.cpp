#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<ll>v;
        int n=weights.size();
        for(int i=1;i<n;i++){
            v.push_back(1ll*weights[i]+1ll*weights[i-1]);
        }
        ll temp=k-1;
        sort(v.begin(),v.end());
        ll mini=0;
        int ind=0;
        while(temp>0){
            mini+=v[ind];
            ind++;
            temp--;
        }
        sort(v.begin(),v.end(),greater<int>());
        ll maxi=0;
        ind=0;
        temp=k-1;
        while(temp>0){
            maxi+=v[ind];
            ind++;
            temp--;
        }

        return maxi-mini;
    }
};