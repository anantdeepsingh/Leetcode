class Solution {
public:
    vector<string>ans;
    map<char,vector<char>>mp;
    void solve(int i,string s,string digits){
        int n=digits.size();
        if(i==n){
            ans.push_back(s);
            return;
        }

        char ch=digits[i];
        for(auto &it:mp[ch]){
            s+=it;
            solve(i+1,s,digits);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        if(digits=="") return ans;
        string s="";
        solve(0,s,digits);
        return ans;
    }
};