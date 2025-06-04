class Solution {
public:
    string lastSubstring(string s) {
        int n=s.size();
        int i=0,j=1,k=0;
        while(j+k<n){
            if(s[i+k]==s[j+k]){
                k++;
            }
            else if(s[i+k]>s[j+k]){
                j=j+k+1;
                k=0;
            }
            else{
                i=max(i+k+1,j); // this 
                j=i+1;
                k=0;
            }
        }
        return s.substr(i);
    }
};