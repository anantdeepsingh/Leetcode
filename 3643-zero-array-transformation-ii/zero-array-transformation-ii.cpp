#include <bits/stdc++.h>
using namespace std;

class STMax {
public:
    vector<int> st, lazy;
    
    STMax(int n) {
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            st[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        st[ind] = max(st[2 * ind + 1], st[2 * ind + 2]);
    }

    void propagate(int ind, int low, int high) {
        if (lazy[ind] != 0) {
            st[ind] += lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
    }

    void update(int ind, int low, int high, int l, int r, int val) {
        propagate(ind, low, high);

        // No overlap
        if (high < l || low > r) return;

        // Complete overlap
        if (low >= l && high <= r) {
            st[ind] += val;
            if (low != high) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        int mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        st[ind] = max(st[2 * ind + 1], st[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        propagate(ind, low, high); 

        // No overlap
        if (high < l || low > r) return INT_MIN;

        // Complete overlap
        if (low >= l && high <= r) return st[ind];

        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return max(left, right);
    }
};

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        STMax st(n);
        st.build(0, 0, n - 1, nums);

        int cnt = 0;
        for (auto& it : queries) {
            int u = it[0], v = it[1], change = -it[2];

            int maxi = st.query(0, 0, n - 1, 0, n - 1);
            if (maxi <= 0) break;

            st.update(0, 0, n - 1, u, v, change);
            cnt++;
        }

        int check = st.query(0, 0, n - 1, 0, n - 1);
        return (check > 0) ? -1 : cnt;
    }
};
