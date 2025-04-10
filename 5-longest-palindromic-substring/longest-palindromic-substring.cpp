class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        // dp[i][j] = length of longest common substring ending at s[i-1] and t[j-1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        int maxLen = 0;
        int endIndex = 0; // End index in original string s

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                    // We need to check if the substring is a valid palindrome
                    int origStart = i - dp[i][j];
                    int revStart = n - j;

                    if (origStart == revStart) { // positions match in original string
                        if (dp[i][j] > maxLen) {
                            maxLen = dp[i][j];
                            endIndex = i; // mark the end of substring in s
                        }
                    }
                }
            }
        }

        return s.substr(endIndex - maxLen, maxLen);
    }
};
