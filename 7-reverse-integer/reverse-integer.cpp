class Solution {
public:
    int reverse(int x) {
        long long num=0;
        int sign=1;
        long long y=x;
        if(y<0){
            y=-y;
            sign=-1;
        }
        while(y>0){
            int rem=y%10;
            num=num*10+rem;
            y=y/10;
        }
        num=num*sign;
        if(num>INT_MAX || num<INT_MIN) return 0;

        return (int)num;
        

    }
};