class Solution {
public:
    bool isPalindrome(int x) {
       if(x==0) return true;
       if(x<0) return false;
       long long temp=0ll;
       int cpy=x;
       while(cpy>0){
        int rem=cpy%10;
        temp=1ll*temp*10+rem;
        cpy=cpy/10;
       }

        return temp==x;

    }
};
/*





453
350+4
354

45759



string s="";
s+='0'+9;



-78
87-
-1
1-
-45
45-

false


x=0 always palindrome

x>0 


*/