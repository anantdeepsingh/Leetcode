class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(int i,int j,int ch,vector<int>& piles){
        if(i>j) return 0;
        if(dp[i][j][ch]!=-1) return dp[i][j][ch];
        int op1=0,op2=0;
        if(ch==1){
            op1=piles[i]+solve(i+1,j,0,piles);
            op2=piles[j]+solve(i,j-1,0,piles);
        }
        else{
            op1=solve(i+1,j,1,piles);
            op2=solve(i,j-1,1,piles);
        }
        return dp[i][j][ch]=max(op1,op2);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.assign(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int maxSum=solve(0,n-1,1,piles);
        int sum=accumulate(piles.begin(),piles.end(),0);
        int leftSum=sum-maxSum;
        return maxSum>leftSum;
    }
};


