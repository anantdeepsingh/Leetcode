class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string>a;
        int n=text.size();
        map<char,int>mp;
        for(auto &it:brokenLetters){
            mp[it]++;
        }
        stringstream ss(text);
        string s;
        int cnt=0;
        while(ss>>s){
            bool flag=true;
            for(auto &i:s){
                if(mp.count(i)){
                    flag=false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};