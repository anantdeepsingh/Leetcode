#define ll long long
class Solution {
public:
    int n;
    ll dp[100005];  // Increased size to avoid out-of-bounds errors
    
    ll solve(int ind, vector<vector<int>>& questions) {
        if (ind >= n) return 0;
        if (dp[ind] != -1) return dp[ind];
        ll npick = solve(ind + 1, questions);
        ll pick = 1ll * questions[ind][0] + solve(ind + questions[ind][1] + 1, questions);
        return dp[ind] = max(npick, pick);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        memset(dp, -1, sizeof(dp)); 
        return solve(0, questions);
    }
};
