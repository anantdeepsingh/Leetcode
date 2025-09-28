class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>mp;
        for(auto &it:nums){
            mp.insert(it);
        }
        int ans=0;
        for(auto &it:mp){
            if(mp.find(it-1)==mp.end()){
                int cnt=1;
                int k=it;
                while(mp.find(k+1)!=mp.end()){
                    cnt++;
                    k++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};