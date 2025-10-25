class Solution {
public:
    int totalMoney(int n) {
        int cnt=1;
        int prev1=1;
        int prev2=1;
        for(int i=2;i<=n;i++){
            if((i-1)%7==0){
                cnt+=prev1+1;
                prev1++;
                prev2=prev1;
            }
            else{
                cnt+=prev2+1;
                prev2++;
            }
        }
        return cnt;
    }
};