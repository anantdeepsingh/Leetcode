class Solution {
public:
    vector<char>dp;
    int n;
    void f(int i,int ch){
        if(i>=(n)) return;
        for(int j=i;j<i+ch && j<n;j++){
           if(dp[j-ch]!='z'){
            dp[j]=dp[j-ch]+1;
           }
           else{
            dp[j]='a';
           }
        }
        f(i+ch,ch*2);
    }
    char kthCharacter(int k) {
        n=k;
       dp.assign(k+1,'#');
       dp[0]='a';
        f(1,1);
        return dp[k-1];
    }
};