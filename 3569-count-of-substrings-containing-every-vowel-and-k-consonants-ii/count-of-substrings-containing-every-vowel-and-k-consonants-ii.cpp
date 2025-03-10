#define ll long long
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        map<char,ll>mp;
        ll cnt=0ll;
        ll l=0ll,r=0ll;
        ll n=1ll*word.size();
        set<char>st={'a','e','i','o','u'};

        vector<int>next(n);
        int ind=n;
        for(int i=n-1;i>=0;i--){
            next[i]=ind;
            char ch=word[i];
            if(st.find(ch)==st.end()){
                ind=i;
            }
        }
        ll ans=0ll;
        while(r<n){
            char ch=word[r];
            if(st.find(ch)!=st.end()){
                mp[ch]++;
            }
            else{
                cnt++;
            }

            while(cnt>k){
                char ch=word[l];
                if(st.find(ch)!=st.end()){
                    mp[ch]--;
                    if(mp[ch]==0){
                        mp.erase(ch);
                    }
                }
                else{
                    cnt--;
                }
                l++;
            }

            while(l<n && cnt==k && mp.size()==5){
                ans+=next[r]-r;
                char ch=word[l];
                if(st.find(ch)!=st.end()){
                    mp[ch]--;
                    if(mp[ch]==0){
                        mp.erase(ch);
                    }
                }
                else{
                    cnt--;
                }
                l++;
            }
            r++;
        }
        cout<<ans<<endl;
        
        return ans;
    }
};