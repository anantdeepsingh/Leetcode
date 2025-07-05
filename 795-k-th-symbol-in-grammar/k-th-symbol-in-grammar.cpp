class Solution {
public:
    int count(int k){
        if(k==1) return 0;
        int pos=0;
        while((1<<pos)<k){
            pos++;
        }
        return 1+count(k-(1<<(pos-1)));
    }
    int kthGrammar(int n, int k) {
        int cnt=count(k);
        return cnt%2==1?1:0;
    }
};