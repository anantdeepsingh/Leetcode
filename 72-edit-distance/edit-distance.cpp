class Solution {
public:
    int dp[501][501];
    int f(int i,int j,string s1,string s2){
        if(j<0){
            return i+1;
        }
        if(i<0){
            return j+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int op1=1e5,op2=1e5,op3=1e5;
        // op1 insert
        // op2 delete
        // op3 replace
        if(s1[i]!=s2[j]){
            op1=min(op1,1+f(i,j-1,s1,s2));
            op2=min(op2,1+f(i-1,j,s1,s2));
            op3=min(op3,1+f(i-1,j-1,s1,s2));
        }
        else{
           return dp[i][j]=f(i-1,j-1,s1,s2);
        }

        return dp[i][j]=min({op1,op2,op3});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        memset(dp,-1,sizeof(dp));
        return f(n-1,m-1,word1,word2);
    }
};