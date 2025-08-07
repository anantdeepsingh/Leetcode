const int mod = 1e9 + 7;

class Solution {
public:
    vector<long long> fact, inv_fact;

    long long pow(long long a, long long b) {
        long long res = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    void preCompute(int n) {
        int N = n;
        fact.resize(N + 1);
        inv_fact.resize(N + 1);

        fact[0] = 1;
        for (int i = 1; i <= N; ++i) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        inv_fact[N] = pow(fact[N], mod - 2);
        for (int i = N - 1; i >= 0; --i) {
            inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
        }
    }

    long long nCr(long long n, long long r) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * inv_fact[r]) % mod) * inv_fact[n - r]) % mod;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        map<int, int> yFreq;

        int maxi = 0;
        for (auto& p : points) {
            int y = p[1];
            yFreq[y]++;
            maxi = max(maxi, yFreq[y]); // Track max count
        }

        preCompute(maxi); // Move this BEFORE nCr usage

        vector<long long> rowComb;
        for (auto& [y, cnt] : yFreq) {
            if (cnt >= 2) {
                rowComb.push_back(nCr(cnt, 2));
            }
        }

        int m = rowComb.size();
        if (m < 2) return 0;

        long long totalSum = 0, squareSum = 0;
        for (long long val : rowComb) {
            totalSum = (totalSum + val) % mod;
            squareSum = (squareSum + val * val % mod) % mod;
        }

        long long ans = ((totalSum * totalSum % mod - squareSum + mod) % mod * pow(2, mod - 2)) % mod;
        return ans;
    }
};
