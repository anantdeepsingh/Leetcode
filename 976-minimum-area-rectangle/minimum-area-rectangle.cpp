class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        map<int,set<int>>mp;
        for(auto &it:points){
            int x=it[0];
            int y=it[1];
            mp[x].insert(y);
        }

        int ans=INT_MAX;
        for (auto it1 = mp.begin(); it1 != mp.end(); ++it1) {
            auto it2 = next(it1);
            for (; it2 != mp.end(); ++it2) {
                int diff = it2->first - it1->first;
                int prev = -1;
                for (auto &y : it1->second) {
                    if (it2->second.count(y)) {
                        if (prev != -1) {
                            ans = min(ans, diff * (y - prev));
                        }
                        prev = y;
                    }
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};