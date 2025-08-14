class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,string &s1,string &s2){
        if(i==0 && j==0) return 0;
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        if(s1[i-1]==s2[j-1]){
            ans=min(ans,f(i-1,j-1,s1,s2));
        }
        else{
            int op1=1+f(i,j-1,s1,s2);
            int op2=1+f(i-1,j-1,s1,s2);
            int op3=1+f(i-1,j,s1,s2);
            ans=min(ans,min({op1,op2,op3}));
        }

        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return f(n,m,word1,word2);
    }
};



// HORSE
//   ROS

//   F(4,2)
//   F(4,1),F(3,2),F(3,3)

//   IF(I<0 && J<0) RETURN 0;
//   IF(I<0) RETURN J+1; INSERT
//   IF(J<0) RETURN I+1 DELETE



// F(0,1)
