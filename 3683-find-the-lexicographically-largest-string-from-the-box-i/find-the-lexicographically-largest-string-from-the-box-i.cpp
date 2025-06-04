class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();

        if(numFriends==1){
            return word;
        }
        int maxLen=n-(numFriends-1); // length of largest lexographic string
        vector<int>count(26,0);
        for(auto it:word){
            count[it-'a']++;
        }


        char ch;
        for(int i=25;i>=0;i--){
            if(count[i]){
                ch='a'+i;
                break;
            }
        }

        string ans="";
        for(int i=0;i<n;i++){
            if(word[i]!=ch) continue;
            int len=min(maxLen,n-i);
            string t=word.substr(i,len);
            ans=max(ans,t);
        }
        return ans;
    }
};