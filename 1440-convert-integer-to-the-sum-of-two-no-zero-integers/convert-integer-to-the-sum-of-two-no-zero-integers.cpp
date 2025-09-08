class Solution {
public:
    bool containZero(int n){
        while(n>0){
            int rem=n%10;
            if(rem==0) return 1;
            n=n/10;
        }
        return 0;
    }
    vector<int> getNoZeroIntegers(int n) {
        int l=1,r=n-1;
        while(l<=r){
           if(!containZero(l) && !containZero(r)){
            return {l,r};
           }
           l++;
           r--;
        }
        return {-1,-1};
    }
};