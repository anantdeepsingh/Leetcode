class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        
        int n=s.size();
        int m=dictionary.size();
        map<int,int>mp;

        for(int i=0;i<m;i++){
            mp[i]=0;
        }
        int maxi=0;
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ind=mp[j];
                if(ind<dictionary[j].size() && s[i]==dictionary[j][ind]){
                    mp[j]++;
                }
                else {
                    mp[j]=ind;
                }
            }
        }


        for(int j=0;j<m;j++){
            if(mp[j]==dictionary[j].size() && mp[j]>maxi){
                maxi=mp[j];
                ans=dictionary[j];
            }
            else if(mp[j]==dictionary[j].size() && mp[j]==maxi){
                if(dictionary[j]<ans){
                    ans=dictionary[j];
                }
            }
        }

        return ans;
    }
};