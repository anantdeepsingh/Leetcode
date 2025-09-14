class Solution {
public:
    int reverse(int x) {
        long long value=0;
        while(x!=0)
        {
            long long rem=x%10;
            value=value*10+rem;
            x=x/10;
        }
        if(value<INT_MIN || value>INT_MAX|| x==-1)
            return 0;
        return value;
        
    }
};