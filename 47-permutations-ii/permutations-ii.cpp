class Solution {
public:
    set<vector<int>>ans;
    void f(int i,unordered_map<int,int>&mp,int n,vector<int>& nums,vector<int>&v){
        // base case
        if(i==n){
            ans.insert(v);
            return;
        }

        // exploring cases

        for(int j=0;j<n;j++){
            if(mp[nums[j]]>0){
                v.push_back(nums[j]);
                mp[nums[j]]--;
                f(i+1,mp,n,nums,v);
                v.pop_back();
                mp[nums[j]]++;
            }
        }


    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;

        for(auto it:nums){
            mp[it]++;
        }
        vector<int>v;
        f(0,mp,n,nums,v);


        vector<vector<int>>res;
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }
};