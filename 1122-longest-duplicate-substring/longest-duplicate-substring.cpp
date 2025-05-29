class Solution {
public:
    long long mod_inv(long long p, long long mod) {
        long long res = 1, exp = mod - 2;
        while (exp) {
            if (exp & 1) res = (res * p) % mod;
            p = (p * p) % mod;
            exp >>= 1;
        }
        return res;
    }

    pair<string, bool> check(int k, string s) {
        int p = 7, mod = 1e9 + 7;
        int n = s.size();
        unordered_map<long long, vector<int>> mp;

        long long hash = 0;
        long long power = 1;

        // Precompute p^(k-1)
        for (int i = 0; i < k - 1; ++i) {
            power = (power * p) % mod;
        }

        // Compute initial hash for the first k-length substring
        for (int i = 0; i < k; ++i) {
            hash = (hash * p + (s[i] - 'a' + 1)) % mod;
        }
        mp[hash].push_back(0);

        for (int i = k; i < n; ++i) {
            // Remove the leftmost character and add the new one
            hash = (hash - (s[i - k] - 'a' + 1) * power % mod + mod) % mod;
            hash = (hash * p + (s[i] - 'a' + 1)) % mod;

            if (mp.count(hash)) {
                for (int start : mp[hash]) {
                    if (s.substr(start, k) == s.substr(i - k + 1, k)) {
                        return {s.substr(start, k), true};
                    }
                }
            }
            mp[hash].push_back(i - k + 1);
        }

        return {"", false};
    }

    string longestDupSubstring(string s) {
        int n = s.size();
        int low = 1, high = n;
        string ans = "";
        while (low <= high) {
            int mid = low + (high - low) / 2;
            auto [res, flag] = check(mid, s);
            if (flag) {
                ans = res;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
