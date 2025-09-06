class Solution {
public:
    bool flag=false;
    map<string,int>mp;
    bool valid(string &t){
        // cout<<mp.count(t);
        return mp.count(t);
    }
    map<int,bool>dp;
    bool solve(int i,string s){
        // cout<<i<<endl;
        int n=s.size();
        if(i==n){
            return true;
        }
        if(dp.count(i)) return dp[i];
        string t="";
        for(int j=i;j<n;j++){
            t+=s[j];
            if(valid(t)){
                if(solve(j+1,s)){
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &it:wordDict){
            mp[it]++;
        }

        return solve(0,s);
    }
};
