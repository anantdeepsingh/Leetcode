class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int hcf=0;
        int n=nums.size();
        int m=numsDivide.size();
        for(int i=0;i<m;i++){
            hcf=__gcd(hcf,numsDivide[i]);
        }
        sort(begin(nums),end(nums));
        int cnt=0;
        for(int i=0;i<n;i++){
            if(hcf<nums[i]) return -1;
            if(hcf%nums[i]==0){
                return cnt;
            }
            cnt++;
        }
        return -1;
    }
};