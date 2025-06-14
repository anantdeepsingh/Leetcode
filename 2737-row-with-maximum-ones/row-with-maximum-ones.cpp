class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ind=-1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    cnt++;
                }
            }
            if(cnt>maxi){
                maxi=cnt;
                ind=i;
            }
        }
        return {ind,maxi};
    }
};