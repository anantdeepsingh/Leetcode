const int mod = 1e9 + 7;

class Solution {
public:
    long long pow(long long a, long long b) {
        if (b == 0) return 1;
        if (b == 1) return a % mod;
        if (b % 2 == 0) {
            long long half = pow((a % mod * a % mod) % mod, b / 2);
            return half % mod;
        }
        return (a % mod * pow((a % mod * a % mod) % mod, b / 2) % mod) % mod;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int i = 31; i >= 0; i--) {
            long long val = (1ll << i);
            if (n >= val) {
                powers.push_back(val % mod);
                n -= val;
            }
        }

        sort(powers.begin(), powers.end());
        int sz = powers.size();
        vector<long long> pr(sz);
        pr[0] = powers[0];
        for (int i = 1; i < sz; i++) {
            pr[i] = (pr[i - 1] * powers[i]) % mod;
        }

        vector<int> ans;
        for (auto &it : queries) {
            int l = it[0], r = it[1];
            if (l == 0) {
                ans.push_back(pr[r] % mod);
            } else {
                long long inv = pow(pr[l - 1], mod - 2);
                ans.push_back((pr[r] * inv) % mod);
            }
        }
        return ans;
    }
};
