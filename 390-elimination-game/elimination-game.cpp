class Solution {
public:
    int lastRemaining(int n) {
       int remain=n;
       bool left=true;
       int head=1,step=1;
       while(remain>1){
        if(left || remain&1){
            head+=step;
        }
        remain/=2;
        step=step*2;
        left=!left;
       }  
       return head;
    }
};