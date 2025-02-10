class Solution {
public:
    int n;
    int dp[1005];

    bool checkBalanced(vector<int>& count) {
        int mini = INT_MAX, maxi = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                mini = min(mini, count[i]);
                maxi = max(maxi, count[i]);
            }
        }
        return mini == maxi; // A balanced substring has equal character counts
    }

    int solve(int ind,string &s) {
       if(ind==n) return 0;
       if(dp[ind]!=-1) return dp[ind];
       int ans=INT_MAX;
       vector<int>count(26,0);
       for(int j=ind;j<n;j++){
            count[s[j]-'a']++;
            if(checkBalanced(count)){
                ans=min(ans,1+solve(j+1,s));
            }
       }

       return dp[ind]=ans;
    }

    int minimumSubstringsInPartition(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        vector<int> count(26, 0);
        return solve(0,s);
    }
};
