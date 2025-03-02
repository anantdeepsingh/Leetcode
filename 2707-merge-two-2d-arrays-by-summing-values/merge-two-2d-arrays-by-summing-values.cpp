class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        for(auto it:nums1){
            int id=it[0];
            int num=it[1];
            mp[id]+=num;
        }
        for(auto it:nums2){
            int id=it[0];
            int num=it[1];
            mp[id]+=num;
        }

        vector<vector<int>>ans;
        for(auto it:mp){
            ans.push_back({it.first,it.second});
        }
        return ans;
    }
};