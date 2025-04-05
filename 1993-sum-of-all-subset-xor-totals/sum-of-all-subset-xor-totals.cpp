class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            int xor_val=0;
            for(int j=0;j<32;j++){
                int bit=(i>>j)&1;
                if(bit==1){
                    xor_val=xor_val^nums[j];
                }
            }
            ans+=xor_val;
        }
        return ans;
    }
};