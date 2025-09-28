class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        int ans=0;
        for(auto &it:mp){
            if(mp.count(it.first-1)==0){
                int cnt=0;
                int k=it.first;
                while(mp.count(k)!=0){
                    cnt++;
                    k++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};