class Solution {
public:
    int reverseBits(int n) {
        int res=0;
       for(int i=1;i<=32;i++){
            res=(res<<1);
            res=res|(n&1);
            n=n>>1;
       }
      return  res;
    }
};