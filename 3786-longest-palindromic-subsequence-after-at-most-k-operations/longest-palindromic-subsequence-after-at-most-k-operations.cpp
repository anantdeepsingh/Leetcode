class Solution {
public:
    vector<vector<vector<int>>>dp;
    int mini(char &a,char &b){
        int diff=abs(a-b);
        return min(diff,26-diff);
    }
    int solve(string &s,int i,int j,int k){
        if(i>j) return 0;
        if(i==j) return 1;
        if(s[i]==s[j]) return dp[i][j][k]=2+solve(s,i+1,j-1,k);
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=max(solve(s,i+1,j,k),solve(s,i,j-1,k));
        int c=mini(s[i],s[j]);
        if(c<=k){
            ans=max(ans,2+solve(s,i+1,j-1,k-c));
        }
        return dp[i][j][k]=ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        dp.resize(n,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return solve(s,0,n-1,k);
    }
};