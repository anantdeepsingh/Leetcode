class Solution {
public:
    int n;
    string t;
    bool checkPalindrome(string temp){
        int i=0,j=temp.size()-1;
        while(i<j){
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int ind,vector<string>&v,vector<vector<string>>&ans){
        if(ind==n){
            cout<<"hello"<<endl;
            ans.push_back(v);
            return;
        }
        string temp="";
        for(int j=ind;j<n;j++){
            temp=temp+t[j];
            if(checkPalindrome(temp)){
                v.push_back(temp);
                solve(j+1,v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        t=s;
        n=s.size();
        vector<string>v;
        vector<vector<string>>ans;
        solve(0,v,ans);

        return ans;
    }
};