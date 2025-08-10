class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        int width=0;
        map<long long,int>mp;
        for(int i=0;i<n;i++){
            long long start=0;
            for(int j=0;j<wall[i].size();j++){
                start+=1ll*wall[i][j];
                mp[start]++;
            }
            width=start;
            if(i==n-1) break;
        }
        int ans=n;
        for(auto &it:mp){
            if(it.first==width) continue;
            ans=min(ans,n-it.second);
        }

        return ans;
    }
};

// 1
// 1
// 1