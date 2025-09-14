class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); 
        // dp[n][0] = dp[n][1] = 0 (base case)

        for (int i = n - 1; i >= 0; i--) {
            // Alice's turn (maximize)
            int op1 = stoneValue[i] + dp[i + 1][0];
            int op2 = (i + 1 < n ? stoneValue[i] + stoneValue[i + 1] + dp[i + 2][0] : INT_MIN);
            int op3 = (i + 2 < n ? stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] + dp[i + 3][0] : INT_MIN);
            dp[i][1] = max({op1, op2, op3});

            // Bob's turn (minimize)
            int bop1 = -stoneValue[i] + dp[i + 1][1];
            int bop2 = (i + 1 < n ? -stoneValue[i] - stoneValue[i + 1] + dp[i + 2][1] : INT_MAX);
            int bop3 = (i + 2 < n ? -stoneValue[i] - stoneValue[i + 1] - stoneValue[i + 2] + dp[i + 3][1] : INT_MAX);
            dp[i][0] = min({bop1, bop2, bop3});
        }

        int val = dp[0][1]; // game starts with Alice

        if (val > 0) return "Alice";
        if (val < 0) return "Bob";
        return "Tie";
    }
};
