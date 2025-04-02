class Solution {
public:
    string countAndSay(int n) {
        
        string s="1";
        for(int i=2;i<=n;i++){

            char last=s[0];

            int cnt=1;
            string t="";
            for(int j=0;j<s.size()-1;j++){
                if(s[j]==s[j+1]){
                    cnt++;
                    last=s[j];
                }
                else{
                    string temp=to_string(cnt);
                    t+=temp;
                    t+=last;
                    cnt=1;
                    last=s[j+1];
                }
            }

            string temp=to_string(cnt);
            t+=temp;
            t+=last;

            s=t;
        }

        return s;
    }
};