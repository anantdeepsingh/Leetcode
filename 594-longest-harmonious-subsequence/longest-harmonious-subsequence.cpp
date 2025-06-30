class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(auto it:nums){
            mp[it]++;
        }
        int maxLen=0;
        for(auto it:mp){
            int op1=it.first;
            int op2=it.first+1;
            if(mp.count(op2)){
                maxLen=max(maxLen,mp[op1]+mp[op2]);
            }
        }
        return maxLen;
    }
};