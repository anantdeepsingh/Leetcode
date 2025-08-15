class Solution {
public:
    bool Check(int n){
        if(n==0) return false;
        if(n==1) return true;
        if(n%4==0) return Check(n/4);
        return false;
    }
    bool isPowerOfFour(int n) {
        if(n<0) return false;
        return Check(n);
    }
};