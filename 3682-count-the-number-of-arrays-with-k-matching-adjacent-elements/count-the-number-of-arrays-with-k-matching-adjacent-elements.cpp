const int mod = 1e9 + 7;
class Solution {
public:
    vector<long long> fact, invFact;
    int MAX;
    long long modpow(long long a, long long b) {
        long long res = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    void precompute() {
        fact[0] = invFact[0] = 1;
        for (int i = 1; i < MAX; ++i) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        invFact[MAX - 1] = modpow(fact[MAX - 1], mod - 2);
        for (int i = MAX - 2; i >= 1; --i) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
        }
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
    }

    int countGoodArrays(int n, int m, int k) {
        MAX=n;
        if(n == (k + 1)) return m;
        fact.resize(n+1);
        invFact.resize(n+1);
        precompute();
        
        long long ans = 1;
        ans = (ans * nCr(n - 1, k)) % mod;
        ans = (ans * m) % mod;
        ans = (ans * modpow(m - 1, n - k - 1)) % mod;
        return (int)ans;
    }
};
