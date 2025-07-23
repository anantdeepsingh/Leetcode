class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        for(auto &it:wordList){
            mp[it]++;
        }

        if(mp.count(endWord)==0) return 0;

        queue<pair<int,string>>q;
        unordered_map<string,int>mark;
        q.push({1,beginWord});
        mark[beginWord]++;
        while(!q.empty()){
            int op=q.front().first;
            string res=q.front().second;
            q.pop();
            if(res==endWord) return op;
            int i=0;
            while(i<res.size()){
                string temp=res;
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(mp.count(temp) && mark.count(temp)==0){
                        mark[temp]++;
                        q.push({op+1,temp}); 
                    }
                }
                i++;
            }
        }

        return 0;
    }
};