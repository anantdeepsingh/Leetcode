class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string first,last;
        int f,l;
        if(x>y){
            first="ab";
            last="ba";
            f=x;
            l=y;
        }
        else{
            first="ba";
            last="ab";
            f=y;
            l=x;
        }

        stack<char>st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            string t="";
            st.push(s[i]);
            while((int)st.size()>1){
                char ch1=st.top();
                st.pop();
                char ch2=st.top();
                st.pop();
                t+=ch2;
                t+=ch1;
                if(t==first){
                    ans+=f;
                }
                else{
                    st.push(ch2);
                    st.push(ch1);
                    break;
                }
                t="";
            }
        }
        string t="";


        while(!st.empty()){
            t+=st.top();
            st.pop();
        }

        reverse(t.begin(),t.end());

        cout<<t<<endl;
        for(int i=0;i<t.size();i++){
            st.push(t[i]);
            string k="";
            while(st.size()>1){
                char ch1=st.top();
                st.pop();
                char ch2=st.top();
                st.pop();
                k+=ch2;
                k+=ch1;
                if(k==last){
                    ans+=l;
                }
                else{
                    st.push(ch2);
                    st.push(ch1);
                    break;
                }
                k="";
            }
        }
        
        return ans;
    }
};