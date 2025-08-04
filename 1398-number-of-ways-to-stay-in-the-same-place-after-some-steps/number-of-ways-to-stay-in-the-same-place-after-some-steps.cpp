const int mod = 1e9 + 7;
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int n = min(arrLen, steps + 1);
        vector<vector<long long>> dp(steps + 1, vector<long long>(n, 0));

        dp[0][0] = 1;

        for (int s = 1; s <= steps; ++s) {
            for (int i = 0; i < n; ++i) {
                dp[s][i] = dp[s - 1][i] % mod; // stay
                if (i - 1 >= 0) dp[s][i] = (dp[s][i] + dp[s - 1][i - 1]) % mod;
                if (i + 1 < n) dp[s][i] = (dp[s][i] + dp[s - 1][i + 1]) % mod;
            }
        }

        return dp[steps][0];
    }
};
