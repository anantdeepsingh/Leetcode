class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }
        int cnt1=0,cnt2=0;
        bool flag=false;
        for(auto it:mp){
            string t=it.first;
            string s=t;
            reverse(s.begin(),s.end());
            if(s==t){
                if(mp[t]==1){
                    flag=true;
                }
                else if(mp[t]>1){
                    if(mp[t]%2==1){
                        cnt1+=(mp[t]-1)*2;
                        flag=true;
                    }
                    else{
                        cnt1+=(mp[t])*2;
                    }
                }
            }
            else{
                cnt2+=min(mp[t],mp[s])*4;
            }
        }

        if(flag){
            cnt1+=2;
        }

        return cnt1+cnt2/2;
    }
};