class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r1=-1,r2=-1,c1=-1,c2=-1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && r1==-1){
                    r1=i;
                }
                if(grid[i][j]==1){
                    r2=i;
                }
            }
        }

        if(r1==-1) return 0;


        int len=r2-r1+1;

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(grid[i][j]==1 && c1==-1){
                    c1=j;
                }
                if(grid[i][j]==1){
                    c2=j;
                }
            }
        }

        // cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;
        int bre=c2-c1+1;
        return len*bre;
    }
};