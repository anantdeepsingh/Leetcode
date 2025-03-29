#define ll long long
class Solution {
public:
    const ll mod = 1e9 + 7;
    ll exponentiation(ll x, ll y, ll p) {
        ll answer = 1;
        x = x % p;
        while (y > 0) {
            if (y & 1) {
                answer = (1LL * answer * x) % p;
            }
            x = (1LL * x * x) % p;
            y >>= 1;
        }
        return answer;
    }

    ll primeFactors(ll n) {
        ll count = 0;
        if (n % 2 == 0) {
            count++;
            while (n % 2 == 0) n /= 2;
        }
        for (ll i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                count++;
                while (n % i == 0) n /= i;
            }
        }
        if (n > 2) count++; 
        return count;
    }

    int maximumScore(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            a[i] = primeFactors(nums[i]);
        }

        vector<ll> next_greater(n, n);
        vector<ll> prev_greater(n, -1);
        stack<ll> st;

        for (ll i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] <= a[i]) {
                st.pop();
            }
            if (!st.empty()) {
                next_greater[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (ll i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] < a[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prev_greater[i] = st.top();
            }
            st.push(i);
        }
        vector<ll> ranges(n, 0);
        for (ll i = 0; i < n; i++) {
            ll left = (prev_greater[i] == -1) ? -1 : prev_greater[i];
            ll right = (next_greater[i] == n) ? n : next_greater[i];
            ranges[i] = (i - left) * (right - i);
        }
        priority_queue<pair<ll, ll>> pq;
        for (ll i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        ll ans = 1;
        while (k > 0) {
            ll top = pq.top().first;
            ll ind = pq.top().second;
            pq.pop();

            ll op = min((ll)k, (ll)ranges[ind]);
            ans = (ans * exponentiation(top, op, mod)) % mod;
            k -= op;
        }

        return ans;
    }
};