class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        stack<string>st;
        for(auto &it:words){
            if(st.empty()) {
                st.push(it);
                continue;
            }

            string t=st.top();
            string s=it;
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            if(s==t) continue;
            else{
                st.push(it);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};