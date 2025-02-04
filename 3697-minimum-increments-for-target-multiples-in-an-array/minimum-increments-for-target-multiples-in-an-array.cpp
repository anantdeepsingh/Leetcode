class Solution {
public: 
    int recursion(int pos, int mask, int n, int m, vector<int> &nums, vector<int> &target, vector<vector<int>> &dp) {
        if(mask == 0) return 0;
        if(pos == n) {
            return INT_MAX;
        }

        if(dp[pos][mask] != -1) {
            return dp[pos][mask];
        } 

        int ans = recursion(pos + 1, mask, n, m, nums, target, dp);

        for(int bit = 0; bit < m; bit++) {
            if(1 & (mask >> bit)) {
                int q = ceil((double)nums[pos] / target[bit]);
                int op = q * target[bit] - nums[pos];
                int newNum = nums[pos] + op;

                int newMask = mask;
                for(int i = 0; i < m; i++) {
                    if((1 & (newMask >> i)) && (newNum % target[i] == 0)) {
                        newMask -= (1 << i);
                    }
                }

                int res = recursion(pos + 1, newMask, n, m, nums, target, dp);
                ans = min(ans, res == INT_MAX ? res : op + res);
            }
        }

        return dp[pos][mask] = ans;
    }

    int minimumIncrements(vector<int> &nums, vector<int> &target) {
        int n = nums.size(), m = target.size();
        
        int mask = (1 << m) - 1;
        vector<vector<int>> dp(n, vector<int> (mask + 1, -1));
        return recursion(0, mask, n, m, nums, target, dp);
    }
};