class Solution {
public:
    int n;
    int dp[1002][1002];

    int solve(int ind, int prev, vector<string>& words, vector<int>& groups) {
        if (ind == n) return 0;
        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int ntake = solve(ind + 1, prev, words, groups);
        int take = 0;

        if (prev == -1) {
            take = 1 + solve(ind + 1, ind, words, groups);
        } else {
            if (groups[ind] != groups[prev] && words[ind].size() == words[prev].size()) {
                int cnt = 0;
                for (int j = 0; j < words[ind].size(); ++j) {
                    if (words[ind][j] != words[prev][j]) cnt++;
                }
                if (cnt == 1) {
                    take = 1 + solve(ind + 1, ind, words, groups);
                }
            }
        }

        return dp[ind][prev + 1] = max(take, ntake);
    }

    bool reconstruct(int ind, int prev, int remaining, vector<string>& words, vector<int>& groups,
                     vector<vector<int>>& count, vector<string>& result) {
        if (remaining == 0) return true;

        for (int i = ind; i < words.size(); ++i) {
            if (dp[i][prev + 1] == remaining) {
                if (prev == -1 || (groups[i] != groups[prev] && count[i][prev] == 1)) {
                    result.push_back(words[i]);
                    if (reconstruct(i + 1, i, remaining - 1, words, groups, count, result)) {
                        return true;
                    }
                    result.pop_back(); // backtrack
                }
            }
        }

        return false;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        n = words.size();
        memset(dp, -1, sizeof(dp));
        int maxi = solve(0, -1, words, groups);

        // Precompute Hamming distances
        vector<vector<int>> count(n, vector<int>(n, 100));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (words[i].size() != words[j].size()) continue;
                int diff = 0;
                for (int k = 0; k < words[i].size(); ++k) {
                    if (words[i][k] != words[j][k]) diff++;
                }
                count[i][j] = diff;
            }
        }

        vector<string> result;
        reconstruct(0, -1, maxi, words, groups, count, result);
        return result;
    }
};
