#define t tuple<int,int,int>
class Solution {
public:
    bool Check(int mid,vector<vector<int>>& heights,int n,int m){
        priority_queue<t,vector<t>,greater<t>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e8));
        pq.push({0,0,0});
        dist[0][0]=0;
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        while(!pq.empty()){
            auto [effort,x,y]=pq.top();
            pq.pop();
            if(x==n-1 && y==m-1){
                return effort<=mid;
            }

            for(int i=0;i<4;i++){
                int nx=x+drow[i];
                int ny=y+dcol[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int neffort=max(effort,abs(heights[nx][ny]-heights[x][y]));
                    if(dist[nx][ny]>neffort){
                        dist[nx][ny]=neffort;
                        pq.push({neffort,nx,ny});
                    }
                }
            }

        }

        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int low=0,high=1e6;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(Check(mid,heights,n,m)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};


//  since the distance b/w adj is not increasign by 1 so pq will be iused
// sgtates dist,i,j