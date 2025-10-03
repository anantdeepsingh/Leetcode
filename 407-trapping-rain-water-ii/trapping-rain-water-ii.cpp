#define t tuple<int,int,int>
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        
        priority_queue<t,vector<t>,greater<t>>pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            pq.push({heightMap[0][i],0,i});
            pq.push({heightMap[n-1][i],n-1,i});
            vis[0][i]=1;
            vis[n-1][i]=1;
        }

        for(int j=1;j<n-1;j++){
            vis[j][0]=1;
            vis[j][m-1]=1;
            pq.push({heightMap[j][0],j,0});
            pq.push({heightMap[j][m-1],j,m-1});
        }


        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        int ans=0;
        while(!pq.empty()){
            auto [ht,x,y]=pq.top();
            pq.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0){
                    if(heightMap[nx][ny]>=heightMap[x][y]){
                        vis[nx][ny]=1;
                        pq.push({heightMap[nx][ny],nx,ny});
                    }
                    else{
                        ans+=heightMap[x][y]-heightMap[nx][ny];
                        vis[nx][ny]=1;
                        heightMap[nx][ny]=heightMap[x][y];
                        pq.push({heightMap[x][y],nx,ny});
                    }
                }
            }
        }
        return ans;
    }
};