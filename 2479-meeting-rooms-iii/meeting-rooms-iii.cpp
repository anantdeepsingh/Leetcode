#define ll long long
#define pi pair<ll, ll>

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        set<ll> availableRooms;
        vector<ll> roomCount(n, 0);

        sort(meetings.begin(), meetings.end());

        for (ll i = 0; i < n; i++) availableRooms.insert(i);

        for (auto& meeting : meetings) {
            ll start = meeting[0];
            ll end = meeting[1];
            ll duration = end - start;

            while (!pq.empty() && pq.top().first <= start) {
                availableRooms.insert(pq.top().second);
                pq.pop();
            }

            if (!availableRooms.empty()) {
                ll room = *availableRooms.begin();
                availableRooms.erase(room);
                pq.push({end, room});
                roomCount[room]++;
            } else {
                auto [free_time, room] = pq.top();
                pq.pop();
                pq.push({free_time + duration, room});
                roomCount[room]++;
            }
        }

        ll maxRoom = 0;
        for (ll i = 1; i < n; i++) {
            if (roomCount[i] > roomCount[maxRoom]) {
                maxRoom = i;
            }
        }

        return maxRoom;
    }
};
