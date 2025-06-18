const int mod=1e9+7;
class Solution {
public:
    string divide(string num, int base, int &remainder) {
    string result;
    int curr = 0;
    remainder = 0;
    for (char c : num) {
        curr = remainder * 10 + (c - '0');
        result += (curr / base) + '0';
        remainder = curr % base;
    }
    int pos = 0;
    while (pos < result.size() && result[pos] == '0') pos++;
    return result.substr(pos);
    }

    string toBase(string num, int base) {
        if (num == "0") return "0";
        string result = "";
        int rem;

        while (!num.empty()) {
            num = divide(num, base, rem);
            if (rem < 10) result += (rem + '0');
            else result += (rem - 10 + 'A'); // For base > 10
        }
        reverse(result.begin(), result.end());
        return result;
    }
    vector<vector<vector<int>>>dp;
    int f(int i,int tight,int prev,string s,int base){
        int n=s.size();
        if(i==n) return 1;
        if(dp[i][tight][prev]!=-1) return dp[i][tight][prev];
        int low=0;
        int high=tight?s[i]-'0':base-1;
        int ans=0;
        for(int j=prev;j<=high;j++){
            int ntight=tight&&(j==(s[i]-'0'));
            ans=(ans%mod+f(i+1,ntight,j,s,base));
        }
        return dp[i][tight][prev]=ans;
    }
    int countNumbers(string l, string r, int b) {
        string k=toBase(r,b);
        int n=k.size();
        dp.assign(n,vector<vector<int>>(2,vector<int>(10,-1)));
        int op1=f(0,1,0,k,b);
        string p=toBase(l,b);
        int m=p.size();
        dp.assign(m,vector<vector<int>>(2,vector<int>(10,-1)));
        int op2=f(0,1,0,p,b);

        
        int ans=1;
        for(int i=1;i<m;i++){
            if(p[i]>=p[i-1]) continue;
            else{
                ans--;
                break;
            }
        }
        ans=(ans%mod+op1%mod-op2%mod+mod)%mod;
        return ans;
    }
};