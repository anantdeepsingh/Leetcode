class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int sz=nums.size();
        int n=sz/2;
        map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second==n) return it.first;
        }
        return -1;
    }
};