class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<long long> a(n);
        
        for (int i = 0; i < n; i++) {
            a[i] = (long long)target[i] - nums[i];
        }
        
        long long ans = 0;
        long long prev = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > prev) {
                ans += a[i] - prev;
            }
            prev = a[i];
        }
        return ans + max(-prev,0ll);
    }
};
