class Solution {
public:
    int maximalSquare(vector<vector<char>>& mt) {

        int n=mt.size();
        int m=mt[0].size();
        vector<vector<int>>matrix(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=(mt[i][j]=='1')?1:0;
            }
        }
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            dp[i][0]=matrix[i][0];
        }


        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0) continue;
                dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt=max(cnt,dp[i][j]);
            }
        }

        return cnt*cnt;
    }
};
