#define pi pair<int,pair<int,int>>
class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int minMoves=INT_MAX;
        int n=matrix.size();
        int m=matrix[0].size();
        if(matrix[n-1][m-1]=='#') return -1;
        map<char,vector<pair<int,int>>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]>=65 && matrix[i][j]<=90){
                    mp[matrix[i][j]].push_back({i,j});
                }
            }
        }
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({0,{0,0}});
        set<char>st;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nx=x+drow[i];
                int ny=y+dcol[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && matrix[nx][ny]!='#' && dist[nx][ny]>1+d){
                    dist[nx][ny]=1+d;
                    pq.push({1+d,{nx,ny}});
                }
            }
            if(matrix[x][y]>=65 && matrix[x][y]<=90 && st.find(matrix[x][y])==st.end()){
                st.insert(matrix[x][y]);
                for(auto it:mp[matrix[x][y]]){
                    if(dist[it.first][it.second]>d){
                        dist[it.first][it.second]=d;
                        pq.push({d,{it.first,it.second}});
                    }
                }
            }
        }

        return dist[n-1][m-1]==INT_MAX?-1:dist[n-1][m-1];
    }
};