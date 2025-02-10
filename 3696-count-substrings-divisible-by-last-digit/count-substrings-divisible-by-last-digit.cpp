#define ll long long

int n;
ll dp[100005][10][10];

ll rec(string&s,int i,int rem,int d){
    if(i==n) return 0;
    if(dp[i][rem][d]!=-1) return dp[i][rem][d];
    int cur=s[i]-'0';
    int nrem=(rem*10+cur)%d;
    ll ans=0;
    if(cur==d and nrem==0) ans++;
    ans+=rec(s,i+1,nrem,d);
    return dp[i][rem][d]=ans;
}

class Solution {
public:
    long long countSubstrings(string s) {
        n=s.size();
        for(int i=0;i<=n;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++) dp[i][j][k]=-1;
        ll ans=0;
        for(int i=1;i<=9;i++) for(int j=0;j<n;j++) ans+=rec(s,j,0,i);
        return ans;
    }
};