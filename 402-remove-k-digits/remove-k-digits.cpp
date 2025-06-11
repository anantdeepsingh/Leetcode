class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(num[i]);
                continue;
            }
            
            while(!st.empty() && k>0 && (st.top()-'a')>(num[i]-'a')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        // if(ans==""){
        //     return "0";
        // }
        // cout<<ans<<endl;
        while(ans.size()>0 && ans[0]=='0'){
            ans.erase(ans.begin());
        }
        if(ans==""){
            return "0";
        }
        return ans;
    }
};