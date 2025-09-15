class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string>a;
        string s="";
        int n=text.size();
        for(int i=0;i<n;i++){
            if(text[i]==32){
                if(s.size()>0) a.push_back(s);
                s="";
            }
            else{
                s+=text[i];
            }
        }
        if(s.size()>0){
            a.push_back(s);
        }
        map<char,int>mp;
        for(auto &it:brokenLetters){
            mp[it]++;
        }
        int cnt=0;
        for(auto &it:a){
            bool flag=true;
            for(auto &i:it){
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