const int mod=1e9+7;
class Solution {
public:
    int dp[23][210][210];
    string subtractOne(string s) {
        int n = s.size();
        int i = n - 1;

        while (i >= 0) {
            if (s[i] > '0') {
                s[i]--;
                break;
            } else {
                s[i] = '9';
                i--;
            }
        }
        if (s[0] == '0') {
            s.erase(0, s.find_first_not_of('0'));
        }
        if (s.empty()) s = "0";

        return s;
    }
    int f(int i,int tight,int sum,int mini,int maxi,int n,string t){
        // base case 
        if(sum>maxi) return 0;
        if(i==n){
            if(sum>=mini && sum<=maxi) return 1;
            return 0;
        }
        if(dp[i][tight][sum]!=-1) return dp[i][tight][sum];
        int ans=0;
        int low=0;
        int high=tight?t[i]-'0':9;
        for(int j=low;j<=high;j++){
            int ntight=tight&&(j==(t[i]-'0'));
            ans=(ans%mod+f(i+1,ntight,sum+j,mini,maxi,n,t)%mod)%mod;
        }
        return dp[i][tight][sum]=ans%mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n=num1.size();
        int m=num2.size();
        string k=subtractOne(num1);
        int len=k.size();
        memset(dp,-1,sizeof(dp));
        int op1=f(0,1,0,min_sum,max_sum,m,num2);
        memset(dp,-1,sizeof(dp));

        int op2=f(0,1,0,min_sum,max_sum,len,k);

        return (op1%mod-op2%mod+mod)%mod;
    }
};