class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        q.push({sr,sc});
        map<pair<int,int>,int>mp;
        mp[{sr,sc}]++;
        image[sr][sc]=color;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+drow[i];
                int ny=y+dcol[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(mp.count({nx,ny})==0 && image[nx][ny]==originalColor){
                        mp[{nx,ny}]++;
                        image[nx][ny]=color;
                        q.push({nx,ny});
                    }
                }
            }
        }

        return image;
    }
};