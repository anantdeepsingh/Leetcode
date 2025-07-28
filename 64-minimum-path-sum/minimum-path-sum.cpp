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
        dp.assign(n,vector<int>(m,0));
       
        dp[n-1][m-1]=grid[n-1][m-1];
        for (int j = m - 2; j >= 0; j--) {
            dp[n-1][j] = grid[n-1][j] + dp[n-1][j+1];
        }

        for (int i = n - 2; i >= 0; i--) {
            dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                int op1=grid[i][j]+dp[i+1][j];
                int op2=grid[i][j]+dp[i][j+1];

                dp[i][j]=min(op1,op2);
            }
        }

        return dp[0][0];
    }
};

// tc: O(n*m)
// sc: O(n*m)