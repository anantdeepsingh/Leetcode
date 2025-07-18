#define t tuple<int,int,int>
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<t, vector<t>, greater<t>> pq;
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while (!pq.empty()) {
            auto [time, x, y] = pq.top();
            pq.pop();
            
            if (x == n-1 && y == n-1) return time;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + drow[i], ny = y + dcol[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    int newTime = max(time, grid[nx][ny]);
                    if (dist[nx][ny] > newTime) {
                        dist[nx][ny] = newTime;
                        pq.push({newTime, nx, ny});
                    }
                }
            }
        }
        
        return -1; // should never reach here
    }
};
