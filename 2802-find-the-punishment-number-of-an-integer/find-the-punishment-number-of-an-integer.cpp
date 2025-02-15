class Solution {
public:
    bool check(int start, int sum, string &s, int target) {
        if (start == s.size()) {
            return sum == target;
        }

        for (int i = start; i < s.size(); i++) {
            string t = s.substr(start, i - start + 1);
            int val = stoi(t);
            if (sum + val > target) break;  
            if (check(i + 1, sum + val, s, target)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            if (check(0, 0, s, i)) {  
                ans += i * i;
            }
        }
        return ans;
    }
};
