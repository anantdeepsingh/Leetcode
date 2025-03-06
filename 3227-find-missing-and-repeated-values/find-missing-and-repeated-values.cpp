class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>vec(n*n+1,0);
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                vec[grid[x][y]]++;
            }
        }
        int a=-1,b=-1;
        for(int x=1;x<=n*n;x++){
            if(vec[x]==2){
                a=x;
            }
            if(vec[x]==0){
                b=x;
            }
        }
        return {a,b};
    }
};