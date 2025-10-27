class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int ans=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            string s=bank[i];
            int cnt=0;
            for(int j=0;j<s.size();j++){
                if(s[j]=='1') cnt++;
            }
            
            if(cnt) v.push_back(cnt);
        }
        for(int i=1;i<v.size();i++){
            ans+=v[i]*v[i-1];
        }
        return ans;
    }
};