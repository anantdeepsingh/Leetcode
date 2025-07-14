class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        // sort(trainers.begin(),trainers.end());
        multiset<int>st(trainers.begin(),trainers.end());
        int ans=0;
        for(auto &it:players){

            auto it1=st.lower_bound(it);
            if(it1==st.end()) continue;
            ans++;
            st.erase(st.find(*it1));
        }
        return ans;
    }
};

/*

4 7 9

2 5 8 8 
*/