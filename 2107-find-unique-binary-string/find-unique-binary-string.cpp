class Solution {
public:
    vector<string>results;
    int n;
    void solve(int ind,string &s){
        if(ind==n){
            results.push_back(s);
            return;
        }

        s+='0';
        solve(ind+1,s);
        s.pop_back();
        s+='1';
        solve(ind+1,s);
        s.pop_back();

    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>st;
        for(auto it:nums){
            st.insert(it);
        }
        n=nums[0].size();
        string s="";
        solve(0,s);
        for(auto it:results){
            if(st.count(it)==0) return it;
        }

        return "";
    }
};