class Solution {
public:
    int calculate(string s) {
        int number=0;
        int sign=1;
        int res=0;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==32) continue;
            if(s[i]>='0' && s[i]<='9'){
                number=number*10+(s[i]-'0');
            }
            else if(s[i]=='('){
                st.push(res);
                // cout<<sign<<endl;
                st.push(sign);
                number=0;
                res=0;
                sign=1;
            }
            else if(s[i]==')'){
                res+=sign*number;
                if(!st.empty()){
                    int sg=st.top();
                    st.pop();
                    int val=st.top();
                    st.pop();
                    res=val+sg*res;
                }
                number=0;
                // sign=1;
            }
            else{
                res+=sign*number;
                if(s[i]=='-'){
                    sign=-1;
                }
                else{
                    sign=1;
                }
                number=0;
            }

            // cout<<res<<endl;
        }
        res+=sign*number;
        return res;
    }
};

