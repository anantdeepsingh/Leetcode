class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int cnt=0;
        map<char,int>mp1;
        map<char,int>mp2;
        for(int i=0;i<n;i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
            if(s1[i]!=s2[i]) cnt++;
        }

        if(cnt==0 || cnt==2 && mp1==mp2) return  true;
        return false;
    }
};