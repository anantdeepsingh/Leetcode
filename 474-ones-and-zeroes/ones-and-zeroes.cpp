class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(int i,int cnt1,int cnt2,vector<pair<int,int>>&count,int n,int m){
        if(i==count.size()) return 0;
        if(dp[i][cnt1][cnt2]!=-1) return dp[i][cnt1][cnt2];
        int op1=solve(i+1,cnt1,cnt2,count,n,m);
        int op2=0;
        if(cnt1+count[i].first<=m && cnt2+count[i].second<=n){
            op2=1+solve(i+1,cnt1+count[i].first,cnt2+count[i].second,count,n,m);
        }
        return dp[i][cnt1][cnt2]=max(op1,op2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k=strs.size();
        vector<pair<int,int>>count(k);
        dp.assign(k,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(int i=0;i<k;i++){
            string s=strs[i];
            int zero=0,one=0;
            for(int j=0;j<s.size();j++){
                if(s[j]=='0') zero++;
                else one++;
            }
            count[i]={zero,one};
        }
        return solve(0,0,0,count,n,m);
    }
};