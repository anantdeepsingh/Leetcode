class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(int i=1;i<=nums.size();i++){
            if(mp.find(i)==mp.end()) return i;
        }
        return nums.size()+1;
    }
};