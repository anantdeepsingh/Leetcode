class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>last;
        int n=s.size();
        for(int i=0;i<n;i++){
            last[s[i]]=i;
        }

        int ind=-1;
        map<char,int>mp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            bool flag=true;
            for(auto it:mp){
                char ch=it.first;
                if(last[ch]>i){
                    flag=false;
                    break;
                }
            }

            if(flag){
                ans.push_back(i-ind);
                ind=i;
            }

        }
        return ans;
    }
};