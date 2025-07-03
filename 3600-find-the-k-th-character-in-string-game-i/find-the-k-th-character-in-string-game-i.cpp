class Solution {
public:
    char kthCharacter(int k) {
        map<char,char>mp;
        for(char ch='a';ch<='y';ch++){
            mp[ch]=ch+1;
        }
        mp['z']='a';

        string s="a";
        while(s.size()<k){
            string t="";
            for(auto it:s){
                t+=mp[it];
            }
            s+=t;
        }

        return s[k-1];
    }
};