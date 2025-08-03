const int mod=1e9+7;
class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int fuel, vector<int>& locations, int finish) {
        if (fuel < 0) return 0;
        if (dp[i][fuel] != -1) return dp[i][fuel];
        int ans = (i == finish) ? 1 : 0; 
        for (int j = 0; j < locations.size(); j++) {
            if (j == i) continue;
            int cost = abs(locations[i] - locations[j]);
            if (cost <= fuel) {
                ans = (ans + solve(j, fuel - cost, locations, finish)) % mod;
            }
        }
        return dp[i][fuel] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        dp.assign(locations.size(), vector<int>(fuel + 1, -1));
        return solve(start, fuel, locations, finish);
    }
};

