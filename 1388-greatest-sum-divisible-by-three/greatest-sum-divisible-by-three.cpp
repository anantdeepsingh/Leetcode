class Solution {
public:
    int dp[40004][3];

    int f(int i, int rem, vector<int>& nums) {
        if (i == nums.size()) {
            if (rem == 0) return 0;   // valid sum (divisible by 3)
            return -1000000000;       // big negative for invalid case
        }
        if (dp[i][rem] != -1) return dp[i][rem];

        // 1) Skip nums[i] → remainder doesn't change
        int op1 = f(i + 1, rem, nums);

        // 2) Take nums[i] → update remainder
        int op2 = nums[i] + f(i + 1, (rem + nums[i]) % 3, nums);

        return dp[i][rem] = max(op1, op2);
    }

    int maxSumDivThree(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));   // mark all states as uncomputed
        return max(0, f(0, 0, nums)); // ensure non-negative answer
    }
};
