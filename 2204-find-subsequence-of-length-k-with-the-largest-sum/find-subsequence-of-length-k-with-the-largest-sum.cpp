class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        auto b=nums;
        sort(b.begin(),b.end(),greater<int>());
        map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[b[i]]++;
        }

        vector<int>ans;
        for(auto it:nums){
            if(mp[it]>0){
                ans.push_back(it);
                mp[it]--;
            }
        }
        return ans;
    }
};