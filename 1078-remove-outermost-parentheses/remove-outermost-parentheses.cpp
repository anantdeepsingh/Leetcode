class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>st;
        string ans="";
        vector<pair<int,int>>v;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')' && st.size()>1){
                st.pop();
            }
            else if(s[i]==')' && st.size()==1){
                int top=st.top();
                st.pop();
                v.push_back({top,i});
            }
        }

        
        for(auto &it:v){
            int l=it.first;
            int r=it.second;
            for(int i=l+1;i<r;i++){
                ans+=s[i];
            }
        }

        return ans;
    }
};

