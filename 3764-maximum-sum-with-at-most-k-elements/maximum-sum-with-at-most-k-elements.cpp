#define ll long long
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<pair<ll,ll>>pq;
        ll sum=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push({1ll*grid[i][j],1ll*i});
            }
        }

        while(k>0){
            ll val=pq.top().first;
            ll ind=pq.top().second;
            pq.pop();
            if(limits[ind]>0){
                sum+=val;
                limits[ind]--;
                k--;
            }
            else{
                continue;
            }
        }
        return sum;
    }
};