class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int l1=s1.length();
       int l2=s2.length();
       vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
    //    return f(l1,l2,s1,s2,dp);
        for(int x=0;x<=l2;x++){
            dp[0][x]=0;
        }
        for(int x=0;x<=l1;x++){
            dp[x][0]=0;
        }
        for(int x=1;x<=l1;x++){
            for(int y=1;y<=l2;y++){
                 if(s1[x-1]==s2[y-1]){
                     dp[x][y]= 1+dp[x-1][y-1];
                }
                else  dp[x][y]=max(dp[x-1][y],dp[x][y-1]);
                    
            }
        }
        int i=l1,j=l2;
        string ans="";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=s1[i-1];
                i--;
            }
            else{
                ans+=s2[j-1];
                j--;
            }
        }
        while(i>0) {
            ans+=s1[i-1];
            i--;
        }
        while(j>0){ 
            ans+=s2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};