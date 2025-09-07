class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int buy,vector<int>&prices,int fee){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int op1=solve(i+1,buy,prices,fee);
        int op2=0;
        if(buy==1){
            op2=max(op2,-fee-prices[i]+solve(i+1,0,prices,fee));
        }
        else{
            op2=max(op2,prices[i]+solve(i+1,1,prices,fee));
        }

        return dp[i][buy]=max(op1,op2);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        return solve(0,1,prices,fee);
    }
};