class Solution {
public:
    int n, maxLenAns = 0, startInd = 0;

    bool check(const string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    void findMaxLen(int ind, int cnt, string &s){
        if(cnt == 0 || ind == n) return;

        for(int j = ind; j < n; j++){
            if(check(s, ind, j)){
                int len = j - ind + 1;
                if(len > maxLenAns){
                    maxLenAns = len;
                    startInd = ind;
                }
                findMaxLen(j + 1, cnt - 1, s);
            }
        }

        findMaxLen(ind + 1, cnt, s);
    }

    string longestPalindrome(string s) {
        n = s.size();
        findMaxLen(0, 1, s);
        return s.substr(startInd, maxLenAns);
    }
};
