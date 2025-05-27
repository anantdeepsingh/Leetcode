class Solution {
public:
    int differenceOfSums(int n, int m) {
        int tsum=(n*(n+1))/2;
        int div=n/m;
        int sum2=m*((div*(div+1))/2);
        return tsum-2*sum2;
    }
};