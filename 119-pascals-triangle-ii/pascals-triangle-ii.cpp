
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans(rowIndex+1);
        ans[0].push_back(1);
        for(int i=1;i<=rowIndex;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    ans[i].push_back(1);
                }
                else{
                    ans[i].push_back(ans[i-1][j]+ans[i-1][j-1]);
                }
            }
        }
        
        return ans[rowIndex];
    }
};
