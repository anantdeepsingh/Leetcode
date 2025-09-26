class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
       for(auto &it:s){
        if(it=='(' || it=='[' || it=='{'){
            st.push(it);
        }
        if(it==')'){
            if(st.empty()) return false;
            if(st.top()=='(') st.pop();
            else return false;
        }
        if(it=='}'){
            if(st.empty()) return false;
            if(st.top()=='{') st.pop();
            else return false;
        }

        if(it==']'){
            if(st.empty()) return false;
            if(st.top()=='[') st.pop();
            else return false;
        }
       }

       return st.empty();
    }
};