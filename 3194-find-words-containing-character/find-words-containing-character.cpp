class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            map<char,int>mp;
            for(int j=0;j<words[i].size();j++){
                mp[words[i][j]]++;
            }

            if(mp.count(x)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};