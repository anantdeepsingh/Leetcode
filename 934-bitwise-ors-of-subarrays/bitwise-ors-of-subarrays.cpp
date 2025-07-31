class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int>st1;
        int ans=0;
        set<int>st3;
        for(auto &it:arr){
            set<int>st2;
            for(auto &i:st1){
                st2.insert(it|i);
            }
            st2.insert(it);
            st1=st2;
            st3.insert(st1.begin(),st1.end());
        }

        return (int)st3.size();
    }
};

/*

0 0 1
0 0 1
0 1 0



0 0 1
0 1 0
1 0 0

*/