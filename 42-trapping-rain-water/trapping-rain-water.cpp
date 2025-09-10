class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        // prefix sum
        vector<int> pre(n, 0);
        pre[0] = height[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + height[i];
        }

        // next greater (to the right)
        stack<int> st;
        vector<int> next_greater(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && height[i] > height[st.top()]) {
                st.pop();
            }
            next_greater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // prev greater (to the left)
        while (!st.empty()) st.pop();
        vector<int> prev_greater(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                st.pop();
            }
            prev_greater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long ans = 0;

        // forward traversal until highest peak
        int r = 0;
        int maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (height[i] > height[maxIdx]) {
                maxIdx = i; // tallest bar index
            }
        }

        while (r < maxIdx) {
            if (height[r] == 0 || next_greater[r] == n) {
                r++;
                continue;
            }
            int ind = next_greater[r];
            if (ind > maxIdx) ind = maxIdx; // don’t cross tallest bar

            ans += 1LL * height[r] * (ind - r - 1);
            if (r + 1 <= ind - 1) {
                ans -= pre[ind - 1] - pre[r];
            }

            r = ind;
        }

        // backward traversal from right until tallest peak
        int l = n - 1;
        while (l > maxIdx) {
            if (height[l] == 0 || prev_greater[l] == -1) {
                l--;
                continue;
            }
            int ind = prev_greater[l];
            if (ind < maxIdx) ind = maxIdx; // don’t cross tallest bar

            ans += 1LL * height[l] * (l - ind - 1);
            if (ind + 1 <= l - 1) {
                ans -= pre[l - 1] - (ind >= 0 ? pre[ind] : 0);
            }

            l = ind;
        }

        return (int)ans;
    }
};
