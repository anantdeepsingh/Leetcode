class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int a=-1,b=-1,c=-1;
        int l=0,r=0;
        int ans=0;
        while(r<n){
            if(s[r]=='a'){
                a=r;
            }
            else if(s[r]=='b'){
                b=r;
            }
            else{
                c=r;
            }

            if(a!=-1 && b!=-1 && c!=-1){
                ans+=min({a,b,c})+1;
            }
            r++;
        }
        return ans;
    }
};