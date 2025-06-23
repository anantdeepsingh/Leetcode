#define ll long long
class Solution {
public:
    vector<ll> palindromes;

    ll createPalindrome(ll x, bool odd) {
        ll res = x, y = (odd ? x / 10 : x);
        while (y > 0) {
            res = res * 10 + y % 10;
            y /= 10;
        }
        return res;
    }

    long long kMirror(int k, int n) {
        ll count = 0, num = 1, sum = 0;

        for (int len = 1; count < n; len++) {
            ll start = pow(10, (len - 1) / 2);
            ll end = pow(10, (len + 1) / 2);

            for (ll i = start; i < end && count < n; ++i) {
                ll p = createPalindrome(i, len % 2);
                string basek = "";
                ll temp = p;
                while (temp) {
                    basek += (temp % k) + '0';
                    temp /= k;
                }
                string rev = basek;
                reverse(rev.begin(), rev.end());
                if (basek == rev) {
                    sum += p;
                    count++;
                }
            }
        }

        return sum;
    }
};
