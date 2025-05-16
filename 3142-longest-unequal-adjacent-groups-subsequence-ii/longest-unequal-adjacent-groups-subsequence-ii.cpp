class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        // Precompute Hamming distances
        vector<vector<int>> hamming(n, vector<int>(n, 100));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (words[i].size() != words[j].size()) continue;
                int diff = 0;
                for (int k = 0; k < words[i].size(); ++k) {
                    if (words[i][k] != words[j][k]) diff++;
                }
                hamming[i][j] = diff;
            }
        }

        vector<int> dp(n, 1);          // dp[i] = longest subsequence ending at i
        vector<int> parent(n, -1);     // to reconstruct the path

        int maxLen = 1, lastIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && hamming[i][j] == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct result
        vector<string> result;
        while (lastIndex != -1) {
            result.push_back(words[lastIndex]);
            lastIndex = parent[lastIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
