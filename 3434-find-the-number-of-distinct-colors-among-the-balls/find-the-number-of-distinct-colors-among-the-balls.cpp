// #define int long long
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       map<int,int>mp1; // for ball
       map<int,int>mp2; // for color
       int cnt=0;
       vector<int>ans;
       for(auto it:queries){
        int ball=it[0];
        int color=it[1];
            if(mp1.find(ball)==mp1.end()){
                mp1[ball]=color;
                mp2[color]++;
            }
            else{
                if(mp1[ball]==color){
                    // mp2[color]++;
                }
                else{
                    mp2[mp1[ball]]--;
                    if(mp2[mp1[ball]]==0){
                        mp2.erase(mp1[ball]);
                    }
                    mp1[ball]=color;
                    mp2[color]++;
                }
            }

            ans.push_back(mp2.size());
       }
       
       return ans;
    }
};