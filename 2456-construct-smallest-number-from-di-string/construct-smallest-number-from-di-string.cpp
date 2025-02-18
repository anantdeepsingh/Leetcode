class Solution {
public:

    // set<string>st;
    bool solve(int ind,string &s,string p,int n,vector<int>&count){
        if(ind==n){
            return true;
        }

        int size=s.size();
        int ch=s[size-1]-'0';
        for(int i=1;i<=9;i++){
            if(count[i]==0) continue;
            if(p[ind]=='D'){
                if(i<ch){
                    s+=i+'0';
                    count[i]--;
                    if(solve(ind+1,s,p,n,count)) return true;
                    count[i]++;
                    s.pop_back();
                }
            }
            else{
                if(i>ch){
                    s+=i+'0';
                    count[i]--;
                    if(solve(ind+1,s,p,n,count)) return true;
                    count[i]++;
                    s.pop_back();
                }
            }
        }

        return false;
    }
    string smallestNumber(string pattern) {
        
        int n=pattern.size();
        for(int i=1;i<=9;i++){
            string s="";
            char ch=i+'0';
            s=s+ch;
            vector<int>count(10,1);
            count[i]--;
            if(solve(0,s,pattern,n,count)) return s;
        }


        // vector<string>a(st.begin(),st.end());

        // for(int i=0;i<a.size();i++){
        //     string s=a[i];
        //     bool flag=true;
        //     for(int j=1;j<s.size();j++){
        //         char ch=pattern[j-1];
        //         if(ch=='I'){
        //             if(s[j]-'0'>s[j-1]-'0') continue;
        //             else {
        //                 flag=false;
        //                 break;
        //             }
        //         }
        //         else{
        //             if(s[j]-'0'<s[j-1]-'0') continue;
        //             else{
        //                 flag=false;
        //                 break;
        //             }
        //         }
        //     }

        //     if(flag) return s;
        // }

        return "";
    }
};
