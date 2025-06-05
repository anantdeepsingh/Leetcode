class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows,vector<int>(numRows,0));
        ans[0][0]=1;
        for(int i=1;i<numRows;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    ans[i][j]=1;
                }
                else{
                    ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
                }
            }
        }
        vector<vector<int>>res(numRows);
        for(int i=0;i<numRows;i++){
            for(int j=0;j<=i;j++){
                res[i].push_back(ans[i][j]);
            }
        }
        return res;
    }
};