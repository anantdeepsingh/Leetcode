class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt=0;
        for(auto it:s){
            if(it=='0'){
                cnt++;
            }
        }

        int ans=cnt;
        int ind=0;
        long long val=0;
        for(int i=s.size()-1;i>=0 && ind<64;i--){
            if(s[i]=='1'){
                val=val|(1ll<<ind);
                if(val<=k){
                    cnt++;
                }
                else{
                    break;
                }
            }
            ind++;
        }

        return cnt;
    }
};