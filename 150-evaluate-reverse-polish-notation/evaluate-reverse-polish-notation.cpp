class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(auto &it:tokens){
            if(it=="*"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                int nval=t2 * t1;
                st.push(nval);
            }
            else if(it=="+"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                int nval=t2 + t1;
                st.push(nval);
            }
            else if(it=="-"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                int nval=t2 - t1;
                st.push(nval);
            }
            else if(it=="/"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                int nval=t2 / t1;
                st.push(nval);
            }
            else{
                int nums=stoi(it);
                st.push(nums);
            }
        }

        if(st.empty()) return 0;

        return st.top();
    }
};