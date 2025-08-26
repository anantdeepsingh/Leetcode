class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        int grps=n/k;
        unordered_map<int,int>mp;
        for(auto &it:nums) mp[it]++;
        for(auto &it:mp){
            if(it.second>grps) return false;
        }
        return true;
    }
};