class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        if(n%k!=0){
            int cnt=k-n%k;
            for(int i=0;i<cnt;i++){
                s+=fill;
            }
        }

        vector<string>ans;
        for(int i=0;i<=s.size()-k;i+=k){
            string t=s.substr(i,k);
            ans.push_back(t);
        }
        return ans;
    }
};