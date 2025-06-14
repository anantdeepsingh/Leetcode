class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                if(matrix[x][y]==target){
                    return true;
                }
            }
        }
        return false;
    }
};