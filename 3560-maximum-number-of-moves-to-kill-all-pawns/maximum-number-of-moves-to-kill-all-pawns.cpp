class Solution {
public:
    vector<vector<int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    void BFS(int x, int y, int index, vector<vector<int>>& minDist, vector<vector<int>>& pos) {
        vector<vector<int>> t(50, vector<int>(50, -1));
        queue<pair<int, int>> que;
        que.push({x, y});
        t[x][y] = 0;

        while(!que.empty()) {
            auto[currX, currY] = que.front();
            que.pop();

            for(auto &dir : directions) {
                int newX = currX + dir[0];
                int newY = currY + dir[1];

                if(newX >= 0 && newX < 50 && newY >= 0 && newY < 50 && t[newX][newY] == -1) {
                    t[newX][newY] = t[currX][currY] + 1;
                    que.push({newX, newY});
                }
            }
        }

        for(int i = 0; i < pos.size(); i++) {
            int x_ = pos[i][0];
            int y_ = pos[i][1];

            minDist[index][i] = t[x_][y_];
        }
    }

    int solve(vector<vector<int>>& minDist, int idx, int mask, int n, bool Alice, int dp[51][1<<15]) {
        if(mask == 0) {
            return 0; //no more moves/steps required
        }

        if(dp[idx][mask] != -1) {
            return dp[idx][mask];
        }

        int result = (Alice == true) ? -1 : 1e9;

        for(int i = 1; i < n; i++) {
            if(mask & (1 << (i-1))) {
                int moves = minDist[idx][i];

                if(Alice == true) {
                    result = max(result, moves + solve(minDist, i, mask ^ (1 << (i-1)), n, !Alice, dp));
                } else {
                    result = min(result, moves + solve(minDist, i, mask ^ (1 << (i-1)), n, !Alice, dp));
                }
            }
        }

        return dp[idx][mask] = result;
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();

        vector<vector<int>> pos;
        pos.push_back({kx, ky});
        for(auto &vec : positions) {
            pos.push_back({vec[0], vec[1]});
        }

        //minDist[][]
        vector<vector<int>> minDist(n+1, vector<int>(n+1, 0));

        for(int i = 0; i < pos.size(); i++) {
            int x = pos[i][0];
            int y = pos[i][1];
            BFS(x, y, i, minDist, pos);
        }


        //call solve
        //0th index par knight hai mera in pos array
        bool Alice = true;
        int dp[51][1 << 15];
        memset(dp, -1, sizeof(dp));
        return solve(minDist, 0, (1<<n)-1, pos.size(), Alice, dp);
    }
};
