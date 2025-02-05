class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();

        map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[s1[i]].push_back(i);
        }
        if(s1==s2) return true;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]) continue;
            for(auto it:mp[s2[i]]){
                int ind=it;
                swap(s1[i],s1[ind]);
                if(s1==s2) return true;
                swap(s1[i],s1[ind]);
            }
        }
        return false;
    }
};