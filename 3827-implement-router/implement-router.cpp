class Router {
public:
    map<int, vector<int>> t; // destination -> sorted timestamps
    int cap;
    map<tuple<int,int,int>,int> mp; // packet existence
    list<tuple<int,int,int>> l;     // FIFO queue

    Router(int memoryLimit) {
        cap = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> pkt = {source,destination,timestamp};
        if(mp.count(pkt)) return false; // already exists

        // Evict if memory full
        if(mp.size() == cap) {
            auto it = l.begin();
            tuple<int,int,int> oldPkt = *it;
            l.pop_front();

            mp.erase(oldPkt);
            int oldDst = get<1>(oldPkt);
            int oldTime = get<2>(oldPkt);
            // Remove oldTime from vector
            auto &vec = t[oldDst];
            auto pos = lower_bound(vec.begin(), vec.end(), oldTime);
            if(pos != vec.end() && *pos == oldTime)
                vec.erase(pos); // O(n) worst case
        }

        // Add new packet
        l.push_back(pkt);
        mp[pkt] = 1;

        // Insert timestamp in sorted order using lower_bound
        auto &vec = t[destination];
        auto pos = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(pos, timestamp); // O(n) worst case
        return true;
    }

    vector<int> forwardPacket() {
        if(l.empty()) return {};

        auto it = l.begin();
        tuple<int,int,int> pkt = *it;
        l.pop_front();

        int src = get<0>(pkt);
        int dst = get<1>(pkt);
        int time = get<2>(pkt);

        // Remove from maps
        mp.erase(pkt);

        // Remove timestamp from vector
        auto &vec = t[dst];
        auto pos = lower_bound(vec.begin(), vec.end(), time);
        if(pos != vec.end() && *pos == time)
            vec.erase(pos);

        return {src, dst, time};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto &vec = t[destination];
        auto it1 = lower_bound(vec.begin(), vec.end(), startTime);
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return it2 - it1; // O(log n)
    }
};
