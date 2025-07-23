class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int timer=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==0){
                    vis[i][j]=1;
                }
            }
        }
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        bool flag=false;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for(int j=0;j<4;j++){
                    int nx=x+drow[j];
                    int ny=y+dcol[j];
                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        if(grid[nx][ny]==1 && !vis[nx][ny]){
                            vis[nx][ny]=1;
                            flag=true;
                            q.push({nx,ny});
                        }
                    }
                }

            }
            timer++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]) return -1;
            }
        }
        
        if(!flag) return 0;

        return timer-1;
    }
};