class Solution {
public:
    string sortVowels(string s) {
        list<char>vowel1,vowel2;
        for(auto &it:s){
            if(it=='A' || it=='E' || it=='I' || it=='O' || it=='U'){
                vowel1.push_back(it);
            }
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u'){
                vowel2.push_back(it);
            }
        }
        vowel1.sort();
        vowel2.sort();
        string t=s;
        map<char,int>mp;
        mp['a']++;
        mp['e']++;
        mp['i']++;
        mp['o']++;
        mp['u']++;
        mp['A']++;
        mp['E']++;
        mp['I']++;
        mp['O']++;
        mp['U']++;
        for(int i=0;i<t.size();i++){
            if(mp.count(t[i])){
                if(vowel1.size()>0){
                    t[i]=*(vowel1.begin());
                    vowel1.pop_front();
                }
                else{
                    t[i]=*(vowel2.begin());
                    vowel2.pop_front();
                }
            }
        }
        return t;
    }
};