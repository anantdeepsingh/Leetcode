#define ll long long
class Solution {
public:
    long long countVowels(string s) {
        ll cnt=0;
        ll n=1ll*s.size();
        ll ans=0ll;
        for(ll i=0;i<n;i++){

            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='u'||s[i]=='i'){
                ans=1ll*ans+1ll*(n-i)+1ll*cnt*(n-i);
            }


            cnt++;
        }
        return ans;
    }
};