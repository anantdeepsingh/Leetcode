class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.size();
        long long cnt=0ll;
        for(int i=n-1;i>=0;i--){
            long long t=(1ll*cnt+1ll*shifts[i])%26;
            s[i]=(s[i]-'a'+t)%26+'a';
            cnt+=1ll*shifts[i];
        }
        return s;
    }
};