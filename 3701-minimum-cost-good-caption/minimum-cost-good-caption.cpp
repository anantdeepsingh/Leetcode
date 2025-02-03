int dp[50004][27][4],n;
string s;
array<int,3> par[50004][27][4];
 
int gap(char a,char b){
    return abs(a-b);
}
 
int rec(int i,int lc,int ct){
    if(i==n) return 0;
    if(dp[i][lc][ct]!=-1) return dp[i][lc][ct];
    int ans=1e9;
    if(ct==3 and n-i>=3){ 
        for(int ch=0;ch<26;ch++){
            int nans;
            if(ch==lc) nans=gap(lc+'a',s[i])+rec(i+1,lc,min(ct+1,3));
            else nans=gap(ch+'a',s[i])+rec(i+1,ch,1);
            if(nans<ans){
                par[i][lc][ct]={i+1,ch,(ch==lc?min(ct+1,3):1)};
                ans=nans;
            }
        }
    }
    else if(lc!=26) {
        ans=gap(lc+'a',s[i])+rec(i+1,lc,min(ct+1,3));
        par[i][lc][ct]={i+1,lc,min(ct+1,3)};
    }
    return dp[i][lc][ct]=ans;
}
 
class Solution {
public:
    string minCostGoodCaption(string ns) {
        s=ns;
        n=s.size();
        for(int i=0;i<=n;i++) for(int j=0;j<=26;j++) for(int k=0;k<=3;k++){
            dp[i][j][k]=-1;
            for(int l=0;l<3;l++)  par[i][j][k][l]=-1;
        }
        rec(0,26,3);
        string ans="";
        array<int,3> cur={0,26,3};
        while(ans.size()<n){
            if(min({cur[0],cur[1],cur[2]})<0) return "";
            cur=par[cur[0]][cur[1]][cur[2]];
            ans+=(char)(cur[1]+'a');
        }
        return ans;
    }
};