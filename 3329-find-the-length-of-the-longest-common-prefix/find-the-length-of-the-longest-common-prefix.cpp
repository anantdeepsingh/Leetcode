class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp;
        for(auto &it:arr1){
            string t=to_string(it);
            string res="";
            for(int i=0;i<t.size();i++){
                res+=t[i];
                mp[res]++;
            }
        }
        int maxi=0;
        for(auto &it:arr2){
            string t=to_string(it);
            string res="";
            for(int i=0;i<t.size();i++){
                res+=t[i];
                if(mp.count(res)){
                    maxi=max(maxi,i+1);
                }
            }
        }
        return maxi;
    }
};