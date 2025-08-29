class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int f(int i,int j,vector<vector<int>>&matrix){

        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        // cout<<i<<" "<<j<<endl;
        int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
        if(j-1>=0){
            op1=min(op1,matrix[i][j]+f(i+1,j-1,matrix));
        }
        if(j>=0){
            op2=min(op2,matrix[i][j]+f(i+1,j,matrix));
        }
        if(j+1<=n-1){
            op3=min(op3,matrix[i][j]+f(i+1,j+1,matrix));
        }

        return dp[i][j]=min({op1,op2,op3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        int ans=INT_MAX;
        dp.assign(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
                if(j-1>=0){
                    op1=min(op1,matrix[i][j]+dp[i+1][j-1]);
                }
                if(j>=0){
                    op2=min(op2,matrix[i][j]+dp[i+1][j]);
                }
                if(j+1<=n-1){
                    op3=min(op3,matrix[i][j]+dp[i+1][j+1]);
                }
                dp[i][j]=min({op1,op2,op3});
            }
        }
        for(int i=0;i<n;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};