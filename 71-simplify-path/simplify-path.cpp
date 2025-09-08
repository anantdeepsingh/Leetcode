class Solution {
public:
    string simplifyPath(string path) {
        string ans="/";
        stack<string>st;
        string s="";
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(s.size()>0){
                    if(s==".." && !st.empty()){
                        st.pop();
                    }
                    else if(s!="." && s!=".."){
                        st.push(s);
                    }
                }
                s="";
            }
            else{
                s+=path[i];
            }
        }
        if(s.size()>0){
            if(s==".." && !st.empty()){
                st.pop();
            }
            else if(s!="." && s!=".."){
                st.push(s);
            }
        }

        ans="";
        vector<string>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
            
        }
        
        reverse(res.begin(),res.end());

        ans="/";

        if(res.size()==0) return ans;
        for(auto &it:res){
            ans+=it;
            ans+="/";
        }
        ans.pop_back();
        return ans;
    }
};