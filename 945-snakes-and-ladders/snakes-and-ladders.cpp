#define ll long long
#define pi pair<ll,ll>

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<ll> dist(n * n + 1, 1e18); // Large initial distance
        dist[1] = 0;

        priority_queue<pi, vector<pi>, greater<pi>> pq; // {moves, cell}
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [moves, node] = pq.top();
            pq.pop();

            if (node == n * n) return moves;

            if (moves > dist[node]) continue; // Skip if we already found a better path

            for (int i = 1; i <= 6 && node + i <= n * n; i++) {
                int next = node + i;
                int row = n - 1 - (next - 1) / n;
                int col = (next - 1) % n;

                if (((next - 1) / n) % 2 == 1) {
                    col = n - 1 - col;
                }

                if (board[row][col] != -1) {
                    next = board[row][col];
                }

                if (dist[next] > moves + 1) {
                    dist[next] = moves + 1;
                    pq.push({moves + 1, next});
                }
            }
        }

        return -1;
    }
};
