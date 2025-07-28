class Solution {
public:

    int n,m;
    vector<vector<int>>dp;
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(i>=n || j>=m){
            return 1e6;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int op1=grid[i][j]+solve(i+1,j,grid);
        int op2=grid[i][j]+solve(i,j+1,grid);

        return dp[i][j]=min(op1,op2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,grid);
    }
};