class Solution {
public:
    int n;
    vector<int> dp; // dp[i] = max score difference starting at i

    int solve(int i, vector<int>& stoneValue) {
        if (i >= n) return 0;
        if (dp[i] != INT_MIN) return dp[i];

        int take = 0;
        int best = INT_MIN;
        for (int k = 0; k < 3 && i + k < n; k++) {
            take += stoneValue[i + k];
            best = max(best, take - solve(i + k + 1, stoneValue));
        }
        return dp[i] = best;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int val = solve(0, stoneValue);

        if (val > 0) return "Alice";
        if (val < 0) return "Bob";
        return "Tie";
    }
};
