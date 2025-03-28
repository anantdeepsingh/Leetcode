#define pi pair<int,pair<int,int>>
class Solution {
public:
    static bool Cmp(pair<int,int>&a,pair<int,int>&b){
        return a.first<b.first;
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        
        int n=grid.size();
        int m=grid[0].size();
        int k=queries.size();
        vector<pair<int,int>>a(k);
        for(int i=0;i<k;i++){
            a[i].first=queries[i];
            a[i].second=i;
        }
        sort(a.begin(),a.end(),Cmp);
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0]=1;

        int cnt=0;
        int ind=0;
        vector<int>ans(k,0);
        

        for(int i=0;i<k;i++){
            int qval=a[i].first;
            int qind=a[i].second;
            while(!pq.empty() && pq.top().first<qval){
                int val=pq.top().first;
                int x=pq.top().second.first;
                int y=pq.top().second.second;
                pq.pop();
                cnt++;
                for(int j=0;j<4;j++){
                    int nx=x+drow[j];
                    int ny=y+dcol[j];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0){
                        vis[nx][ny]=1;
                        pq.push({grid[nx][ny],{nx,ny}});
                    }
                }
            }

            ans[qind]=cnt;
        }
        return ans;
    }
};