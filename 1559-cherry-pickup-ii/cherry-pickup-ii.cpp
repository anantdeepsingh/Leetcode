class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(int i,int j,int k,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        if(j<0 || k<0 || j>=m || k>=m) return 0;
        if(i==n) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=0;
        if(j==k){
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    ans=max(ans,grid[i][j]+solve(i+1,j-x,k-y,grid));
                }
            }
        }
        else{
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    ans=max(ans,grid[i][j]+grid[i][k]+solve(i+1,j-x,k-y,grid));
                }
            }
        }

        return dp[i][j][k]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,grid);
    }
};

// i would be same for both 


// (1,1,3),(1,1,)