class Solution {
public:
    int longestValidParentheses(string s) {
        int  maxLen=0;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    // i dont found any matching
                    // substring breaks here from next i have to strart here
                    st.push(i);
                }
                else{
                    maxLen=max(maxLen,i-st.top());
                }
            }
        }

        return maxLen;
    }
};