class Solution {
public:
    int n;
    vector<vector<vector<vector<int>>>> dp;

    int solve(int r1, int c1, int r2, int c2, vector<vector<int>>& grid) {
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n)
            return -1e6;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e6;

        if (r1 == n - 1 && c1 == n - 1 && r2 == n - 1 && c2 == n - 1)
            return grid[r1][c1];  // End cell

        if (dp[r1][c1][r2][c2] != -1)
            return dp[r1][c1][r2][c2];

        int val = 0;
        if (r1 == r2 && c1 == c2)
            val += grid[r1][c1];
        else
            val += grid[r1][c1] + grid[r2][c2];

        int op1 = solve(r1 + 1, c1, r2 + 1, c2, grid);
        int op2 = solve(r1 + 1, c1, r2, c2 + 1, grid);
        int op3 = solve(r1, c1 + 1, r2 + 1, c2, grid);
        int op4 = solve(r1, c1 + 1, r2, c2 + 1, grid);

        val += max({op1, op2, op3, op4});
        return dp[r1][c1][r2][c2] = val;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp = vector<vector<vector<vector<int>>>>(
            n, vector<vector<vector<int>>>(
                n, vector<vector<int>>(
                    n, vector<int>(n, -1)
                )
            )
        );

        int result = solve(0, 0, 0, 0, grid);
        return max(0, result);
    }
};
