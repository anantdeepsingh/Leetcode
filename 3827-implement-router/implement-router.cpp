#define pi pair<int,pair<int,int>>
class Router {

static bool Cmp(pi&a,pi&b){
    return a.first<b.first;
}
public:
    int k;
    vector<pi>vec;
    vector<int>time;
    set<pi>st;
    map<int,vector<int>>mp;
    Router(int memoryLimit) {
        k=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        pi val={timestamp,{source,destination}};
        if(st.find(val)!=st.end()) return false;
        if(vec.size()==k){
            int t=vec[0].first;
            int s=vec[0].second.first;
            int d=vec[0].second.second;
            st.erase({t,{s,d}});
            vec.erase(vec.begin());
            time.erase(time.begin());
            mp[d].erase(mp[d].begin());
        }

        st.insert({timestamp,{source,destination}});
        vec.push_back({timestamp,{source,destination}});
        time.push_back({timestamp});
        mp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(vec.size()==0) return {};
        int t=vec[0].first;
        int s=vec[0].second.first;
        int d=vec[0].second.second;
        st.erase({t,{s,d}});
        vec.erase(vec.begin());
        time.erase(time.begin());
        mp[d].erase(mp[d].begin());
        return {s,d,t};
    }
    
    int getCount(int destination, int startTime, int endTime) {

        int d=destination;
        auto it1=lower_bound(mp[d].begin(),mp[d].end(),startTime);
        auto it2=upper_bound(mp[d].begin(),mp[d].end(),endTime);
        return distance(it1,it2);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */