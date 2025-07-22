#define t tuple<int,int,int>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<t,vector<t>,greater<t>>pq;
        vector<vector<int>>dist(n,vector<int>(n,1e9));

        if(grid[0][0]!=0) return -1;
        pq.push({1,0,0});
        dist[0][0]=1;

        while(!pq.empty()){
            auto [length,x,y]=pq.top();
            pq.pop();

            if(x==n-1 && y==n-1){
                return length;
            }

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0) continue;

                    int nx=x+i;
                    int ny=y+j;

                    if(nx>=0 && nx<n && ny>=0 && ny<n){
                        if(grid[nx][ny]==0){
                            if(dist[nx][ny]>length+1){
                                dist[nx][ny]=length+1;
                                pq.push({length+1,nx,ny});
                            }
                        }
                    }
                }
            }
        }

        return -1;
    }
};