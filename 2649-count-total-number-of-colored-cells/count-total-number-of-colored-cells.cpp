#define ll long long
class Solution {
public:
    long long coloredCells(int n) {
        
        if(n==1) return 1;

        ll value=2;
        ll prev=1;
        ll res=0;
        while(value<=n){
            res=value*value+prev*prev;
            prev=value;
            value++;
        }
        return res;
    }
};