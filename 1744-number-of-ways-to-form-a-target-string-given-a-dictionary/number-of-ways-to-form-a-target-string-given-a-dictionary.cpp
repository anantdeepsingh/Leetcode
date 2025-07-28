const int mod = 1e9 + 7;
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> mark;
    vector<vector<int>> dp;

    int solve(int i, int j, string &target) {
        if (j == n) return 1; 
        if (i == m) return 0;  

        if (dp[i][j] != -1) return dp[i][j];

        long long ans = solve(i + 1, j, target); // skip

        int ind = target[j] - 'a';

        if (mark[ind][i]) {
            ans = (ans + mark[ind][i] * 1LL * solve(i + 1, j + 1, target)) % mod;
        }

        return dp[i][j] = ans;
    }

    int numWays(vector<string>& words, string target) {
        m = words[0].size();
        n = target.size();
        mark.assign(26, vector<int>(m, 0));
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < m; j++) {
                int ind = words[i][j] - 'a';
                mark[ind][j]++;
            }
        }
        dp.assign(m, vector<int>(n, -1));
        return solve(0, 0, target);
    }
};
