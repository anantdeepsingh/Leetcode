class Solution {
public:
    string clearDigits(string s) {
        set<char>digits;
        for(int i=0;i<=9;i++){
            char ch=i+'0';
            digits.insert(ch);
        }
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(digits.find(ch)!=digits.end()){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};