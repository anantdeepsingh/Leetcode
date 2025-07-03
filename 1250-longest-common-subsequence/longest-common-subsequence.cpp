class Solution {
public:
    string s1,s2;
    int n,m;
    vector<vector<int>>dp;
    int f(int i,int j){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
            ans=max(ans,1+f(i+1,j+1));
        }
        else{
            ans=max({ans,f(i+1,j),f(i,j+1)});
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        s1=text1;
        s2=text2;
        n=s1.size();
        m=s2.size();
        dp.assign(n,vector<int>(m,-1));
        return f(0,0);
    }
};