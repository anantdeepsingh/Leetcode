class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int k, vector<vector<int>>&pre) {
        if (k == 0) return 0;
        if (i == n) return -1e5;

        if (dp[i][k] != -1) return dp[i][k];

        int op1 = solve(i + 1, k, pre); 

        int op2 = INT_MIN;
       
        for(int j=0;j<pre[i].size();j++){
            if(k>=j+1){
                op2=max(op2,pre[i][j]+solve(i+1,k-j-1,pre));
            }
        }
        return dp[i][k] = max(op1, op2);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        dp.assign(n + 1, vector<int>(k + 1, -1));

        vector<vector<int>>pre(n);
        for (int i = 0; i < n; i++) {
            int m=piles[i].size();
            if(m==0){
                continue;
            }
            vector<int>val(m,0);
            val[0]=piles[i][0];
            for(int j=1;j<piles[i].size();j++){
                val[j]=val[j-1]+piles[i][j];
            }

            pre[i]=val;
        }
    
        return solve(0, k, pre);
    }
};
