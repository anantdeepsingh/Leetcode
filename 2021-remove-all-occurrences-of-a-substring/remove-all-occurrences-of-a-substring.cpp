class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        
        stack<char>st;
        for(int i=0;i<n;i++){
            st.push(s[i]);
            if(st.size()>=m){
                string newString="";
                int cnt=0;
                while(cnt<m && !st.empty()){
                    newString+=st.top();
                    st.pop();
                    cnt++;
                }
                reverse(newString.begin(),newString.end());
                if(newString!=part){
                    for(int i=0;i<m;i++){
                        st.push(newString[i]);
                    }
                }
            }
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};