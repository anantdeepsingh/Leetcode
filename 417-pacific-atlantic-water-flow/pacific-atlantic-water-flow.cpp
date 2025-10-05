class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0)),atlantic(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            pacific[0][i]=1;
            atlantic[n-1][i]=1;
        }
        for(int i=0;i<n;i++){
            pacific[i][0]=1;
            atlantic[i][m-1]=1;
        }

        vector<vector<int>>vis1(n,vector<int>(m,0)),vis2(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j]){
                    vis1[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && heights[nx][ny]>=heights[x][y] && vis1[nx][ny]==0){
                    atlantic[nx][ny]=1;
                    vis1[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]){

                    vis2[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && heights[nx][ny]>=heights[x][y] && vis2[nx][ny]==0){
                    pacific[nx][ny]=1;
                    vis2[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }


        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};