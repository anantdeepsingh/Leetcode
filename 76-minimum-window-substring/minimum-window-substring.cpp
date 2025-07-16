class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        int n=s.size();
        int m=t.size();
        for(auto &it:t){
            mp[it]++;
        }
        int minLen=1e9;
        int sInd=-1;
        int l=0,r=0;
        int cnt=0;
        while(r<n){
            if(mp[s[r]]>0){
                cnt++;
            }
            mp[s[r]]--;
            while(cnt==m){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    sInd=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }

        return sInd==-1?"":s.substr(sInd,minLen);
    }
};