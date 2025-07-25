class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n=a.size();
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                if(i==j) continue;
                if(i<j){
                    swap(a[i][j],a[j][i]);
                }
           } 
        }

        for(int i=0;i<n;i++){
            reverse(a[i].begin(),a[i].end());
        }
    }
};