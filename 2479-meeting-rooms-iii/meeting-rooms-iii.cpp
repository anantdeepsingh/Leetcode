#define pi pair<long long,int>
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        priority_queue<int, vector<int>, greater<int>> f;

        for (int i = 0; i < n; i++) f.push(i);

        vector<int> count(n, 0);

        for (auto &it : meetings) {
            while (!pq.empty() && pq.top().first <= it[0]) {
                int t = pq.top().second;
                pq.pop();
                f.push(t);
            }

            if (!f.empty()) {
                int t = f.top();
                f.pop();
                pq.push({1ll*it[1], t});
                count[t]++;
            } else {
                int gap = it[1] - it[0];
                auto [ntime, t] = pq.top();
                pq.pop();
                pq.push({1ll*ntime + 1ll*gap, t});
                count[t]++;
            }
        }

        int maxCount = *max_element(count.begin(), count.end());
        for (int i = 0; i < n; i++) {
            if (count[i] == maxCount) return i;
        }

        return 0;
    }
};
