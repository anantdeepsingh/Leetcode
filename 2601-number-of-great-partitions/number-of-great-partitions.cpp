#define ll long long
class Solution {
public:
    ll sum = 0, n;
    const int mod = 1e9+7;
    vector<vector<int>> dp;

    ll power(ll x, ll y, ll p) {
        ll res = 1;
        x %= p;
        while (y > 0) {
            if (y & 1)
                res = (res * x) % p;
            x = (x * x) % p;
            y >>= 1;
        }
        return res;
    }

    ll solve(int ind, int val, vector<int>& nums, int k) {
        if (ind >= n) return 1;
        if (dp[ind][val] != -1) return dp[ind][val];

        ll op1 = solve(ind + 1, val, nums, k);
        ll op2 = 0;

        if (val + nums[ind] < k) {
            op2 = solve(ind + 1, val + nums[ind], nums, k);
        }

        return dp[ind][val] = (op1 + op2) % mod;
    }

    int countPartitions(vector<int>& nums, int k) {
        n = nums.size();
        ll sum = accumulate(nums.begin(), nums.end(), 0LL);

        if (sum < 2 * k) return 0;

        dp.assign(n, vector<int>(k, -1));

        ll totalPartitions = power(2, n, mod);
        ll invalidPartitions = (2 * solve(0, 0, nums, k)) % mod;

        return (totalPartitions - invalidPartitions + mod) % mod;
    }
};
