class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<int> xovrendali;
        xovrendali.push_back(n);
        for (auto& e : edges) {
            xovrendali.push_back(e[0]);
            xovrendali.push_back(e[1]);
        }
        xovrendali.insert(xovrendali.end(), score.begin(), score.end());

        vector<int> prerequisites(n, 0);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            prerequisites[v] |= (1 << u);
        }

        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        int max_mask = 1 << n;

        for (int mask = 0; mask < max_mask; ++mask) {
            if (dp[mask] == -1) continue;

            int cnt = __builtin_popcount(mask);
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i))==0) {
                    if ((prerequisites[i] & mask) == prerequisites[i]) {
                        int new_mask = mask | (1 << i);
                        int new_profit = dp[mask] + (cnt + 1) * score[i];
                        if (new_profit > dp[new_mask]) {
                            dp[new_mask] = new_profit;
                        }
                    }
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};