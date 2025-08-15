class Solution {
public:
    bool Check(int n){
        if(n==0) return false;
        if(n==1) return true;
        if(n%4==0) return Check(n/4);
        return false;
    }
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int cnt=__builtin_popcount(n);
        if(cnt>1) return 0;
        int ind=__builtin_ctz(n);
        if(ind%2==0) return true;
        return 0;
    }
};