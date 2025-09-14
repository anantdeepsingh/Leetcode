struct Trie{
    int count;
    unordered_map<string,Trie*>mp;
    Trie(){
        count=0;
    }
};
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        Trie* root=new Trie();
        long long ans=0ll;
        for(auto it:words){
            int n=it.size();
            Trie* curr=root;
            for(int i=0;i<n;i++){
                string s="";
                s.push_back(it[i]);
                s.push_back(it[n-i-1]);
                if(curr->mp[s]==NULL){
                    curr->mp[s]=new Trie();
                }
                curr=curr->mp[s];
                ans+=1ll*(curr->count);
            }
            curr->count+=1;
        }
        return ans;
    }
};


