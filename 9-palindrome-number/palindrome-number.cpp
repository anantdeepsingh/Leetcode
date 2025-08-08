class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0) return true;
        if(x<0) return false;
        string s=to_string(x);
        int len=s.size();

        int left=0,right=len-1;
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }


        return true;
    }
};
/*



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