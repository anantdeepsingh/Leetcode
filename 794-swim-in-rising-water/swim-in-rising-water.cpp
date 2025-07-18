#define t tuple<int,int,int>
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<t,vector<t>,greater<t>>pq;
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],0,0});
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(n,0));
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            int time=get<0>(tp);
            int x=get<1>(tp);
            int y=get<2>(tp);
            for(int i=0;i<4;i++){
                int nx=x+drow[i];
                int ny=y+dcol[i];

                if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]==0){
                    if(grid[nx][ny]>time){
                        if(dist[nx][ny]>grid[nx][ny]){
                            dist[nx][ny]=grid[nx][ny];
                            pq.push({dist[nx][ny],nx,ny});
                            vis[nx][ny]=1;
                        }
                        
                    }
                    else{
                        if(dist[nx][ny]>time){
                            dist[nx][ny]=time;
                            pq.push({time,nx,ny});
                            vis[nx][ny]=1;
                        }
                        
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};