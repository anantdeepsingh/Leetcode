class Solution {
public:
    int n, maxLenAns = 0, startInd = 0;
    vector<vector<int>> dp;

    bool check(const string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int findMaxLen(int ind, int cnt, string &s){
        if (cnt == 0 || ind == n) return 0;
        if (dp[ind][cnt] != -1) return dp[ind][cnt];

        int op1 = findMaxLen(ind + 1, cnt, s);  // skip current index
        int op2 = 0;

        for (int j = ind; j < n; j++) {
            if (check(s, ind, j)) {
                int len = j - ind + 1;
                int total = len + findMaxLen(j + 1, cnt - 1, s);
                if (total > op2) {
                    op2 = total;
                    if (cnt == 1 && len > maxLenAns) {  // we only want 1 palindrome
                        maxLenAns = len;
                        startInd = ind;
                    }
                }
            }
        }

        return dp[ind][cnt] = max(op1, op2);
    }

    string longestPalindrome(string s) {
        n = s.size();
        dp.assign(n + 1, vector<int>(2, -1));  // cnt only goes up to 1
        findMaxLen(0, 1, s);
        return s.substr(startInd, maxLenAns);
    }
};
