class Solution {
public:
    set<string>ans;
    void solve(int ind,vector<int>&count,int n,string &s){
        if(ind==n){
            if(s.size()>0){
                ans.insert(s);
            }
            return;
        }
        solve(ind+1,count,n,s);
        for(int i=0;i<26;i++){
            if(count[i]>0){
                count[i]--;
                s.push_back('A'+i);
                solve(ind+1,count,n,s);
                s.pop_back();
                count[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int>count(26,0);
        int n=tiles.size();
        for(int i=0;i<n;i++){
            count[tiles[i]-'A']++;
        }
        string s="";
        solve(0,count,n,s);
        return ans.size();
    }
};