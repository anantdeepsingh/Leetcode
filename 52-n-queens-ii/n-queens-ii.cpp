class Solution {
public:
    bool canI(int i,int j,vector<vector<int>>&vis,int n){
        for(int x=0;x<i;x++){
            if(vis[x][j]) return false;
        }

        for(int y=0;y<j;y++){
            if(vis[i][y]) return false;
        }
        int x=i,y=j;
        while(x>=0 && y<n){
            if(vis[x][y]) return false;
            x--;
            y++;
        }
        x=i;
        y=j;
        while(x>=0 && y>=0){
            if(vis[x][y]) return false;
            x--;
            y--;
        }

        return true;
    }
    int ans=0;
    void f(int i,int n,vector<vector<int>>vis){
        // base case 
        if(i==n){
            ans++;
            return;
        }

        for(int j=0;j<n;j++){
            if(canI(i,j,vis,n)){
                vis[i][j]=1;
                f(i+1,n,vis);
                vis[i][j]=0;
            }
        }
        // return;
    }
    int totalNQueens(int n) {
        vector<vector<int>>vis(n,vector<int>(n,0));
        f(0,n,vis);

        return ans;
    }
};