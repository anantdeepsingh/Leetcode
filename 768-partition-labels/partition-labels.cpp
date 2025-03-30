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
        int end=-1;
        for(int i=0;i<n;i++){
           end=max(end,last[s[i]]);
           if(end==i){
            ans.push_back(i-ind);
            ind=i;
           }

        }
        return ans;
    }
};