class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor_value=0;
        for(int i=0;i<=n;i++){
            xor_value^=i;
        }
        for(auto &it:nums){
            xor_value^=it;
        }
        return xor_value;
    }
};