class Solution {
public:
    int pow(int n,int m){
        if(m==1){
            return n;
        }

        int ans=1;
        if(m%2==0){
            ans=ans*pow(n,m/2);
        }
        else{
            ans=ans*n*pow(n*n,m/2);
        }
        return ans;
    }
    double solve(double x ,long long n){
        if(n==0) return 1.0;
        if(n<0) return solve(1/(1.0*x),-1ll*n);
        if(n%2==0) return solve(x*x,1ll*n/2);
        return x*solve(x*x,n/2);
    }
    double myPow(double x, int n) {
       return solve(x,1ll*n);
    }
};