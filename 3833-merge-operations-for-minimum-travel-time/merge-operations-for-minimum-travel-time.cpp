class Solution {
public:
    int dp[51][11][101];
    int f(int i, int k, int t, vector<int>& positions, vector<int>& time, vector<int>& prefix) {
        int n = time.size();
        if (i == n - 1) {
            if (k > 0) return 1e8;
            return 0;
        }
        if(dp[i][k][t]!=-1) return dp[i][k][t];
        int ans = 1e8;
        for (int j = i + 1; j < n; j++) {
            int ch = j - i- 1; 
            if (k >= ch) {
                int cost = (positions[j] - positions[i]) * t;
                ans = min(ans, cost + f(j, k - ch, prefix[j]-prefix[i], positions, time, prefix));
            }
        }
        return dp[i][k][t]=ans;
    }

    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        vector<int> prefix(n, 0);
        prefix[0] = time[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + time[i];
        }
        int t = time[0]; 
        memset(dp,-1,sizeof(dp));
        return f(0, k, t, position, time, prefix);
    }
};
