#define ll long long
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char,int>mp;
        for(auto &it:word2){
            mp[it]++;
        }

        int cnt=0,l=0,r=0;
        int n=word1.size();
        int m=word2.size();
        ll ans=0ll;
        while(r<n){
            if(mp[word1[r]]>0){
                cnt++;
            }
            mp[word1[r]]--;
            bool flag=false;
            ll left=0ll;
            while(cnt==m){
                left++;
                flag=true;
                mp[word1[l]]++;
                if(mp[word1[l]]>0){
                    cnt--;
                }
                l++;
            }

            if(flag){
                ans+=1ll*(left-1)*1ll*(n-1-r)+1ll*left-1ll+1ll*(n-1-r)+1ll;
            }
            r++;
        }

        return ans;
    }
};