class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int f(int i,int j,vector<vector<int>>& triangle){
        if(i==n) return 0;
        int m=triangle[i].size();
        if(j>=m) return 1e6;
        if(dp[i][j]!=1e8) return dp[i][j];
        int ans=INT_MAX;
        int op1=f(i+1,j,triangle);
        int op2=f(i+1,j+1,triangle);
        return  dp[i][j]=triangle[i][j]+min(op1,op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        dp.assign(n,vector<int>(n+1,1e8));
        return f(0,0,triangle);
    }
};