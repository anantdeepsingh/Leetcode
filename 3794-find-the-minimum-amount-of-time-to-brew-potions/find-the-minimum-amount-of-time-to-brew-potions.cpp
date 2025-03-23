#define ll long long 
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<ll>prefix(n+1,0ll);
        unordered_map<ll,ll>mp;
        prefix[0]=1ll*skill[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+1ll*skill[i];
        }

        ll t=0ll;

        for(int i=0;i<n;i++){
            mp[i]=t+1ll*skill[i]*mana[0];
            t=mp[i];
        }

        for(int i=1;i<m;i++){
            ll time=0LL;
            ll val=1ll*mana[i];
            for(int j=0;j<n;j++){
                if(j==0){
                    time=max(time,mp[j]);
                }
                else{
                    time=max(time,mp[j]-prefix[j-1]*1ll*val);
                }
            }
            
            for(int j=0;j<n;j++){
                mp[j]=time+1ll*skill[j]*val;
                time=mp[j];
            }
        }
        return mp[n-1];
    }
};