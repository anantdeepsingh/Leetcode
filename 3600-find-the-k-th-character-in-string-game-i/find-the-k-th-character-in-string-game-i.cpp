class Solution {
public:
    char kthCharacter(int k) {
       
        string s="a";
        while(s.size()<k){
            string t="";
            for(auto it:s){
                if(it!='z'){
                    t+=(it+1);
                }
                else{
                    t+='a';
                }
            }
            s+=t;
        }

        return s[k-1];
    }
};