int dp[2002][2002], dp2[2001][2002];
class Solution {
public:
    int longestPalindrome(string s, string t) {
        int splitPt = s.size();
        s += t;
        int n = s.size();
        int ans = 0;
        memset(dp, 0, sizeof(dp)); 
memset(dp2, 0, sizeof(dp2)); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1] > 0)) {
                    dp[j][i] = max(dp[j][i], i - j + 1);
                    ans = max(ans, i - j + 1);
                }
            }
        }
        vector<int> maxFromBefore(n, 1), maxAtAfter(n, 1); 
        for(int i = 0; i < n; i++){
            int maxVal = 1;
            for(int j = 0; j < n; j++){
                if(i < splitPt && j < splitPt){
                    maxVal = max(maxVal, dp[i][j]);
                }
            }
            maxFromBefore[i] = maxVal;
        }
        for(int i = n-1; i >= 0; i--){
            int maxVal = 1;
            for(int j = i; j >= 0; j--){
                if(i >= splitPt && j >= splitPt){
                    maxVal = max(maxVal, dp[j][i]);
                }
            }
            maxAtAfter[i] = maxVal;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if(i < splitPt) continue;
                if(j >= splitPt) continue;
                if (s[i] == s[j]) {
                    int max1 = maxFromBefore[j+1], max2 = maxAtAfter[i-1];
                    if(j+1 >= splitPt) max1 = 0;
                    if(i-1 < splitPt) max2 = 0;

                    dp2[j][i] = max({2 + (j + 1 <= i - 1 ? dp2[j + 1][i - 1] : 0), max1 + 2, max2 + 2});
                    ans = max(ans, dp2[j][i]);
                }
            }
        }

        return ans;
    }
};

// dwbbykoyfwd