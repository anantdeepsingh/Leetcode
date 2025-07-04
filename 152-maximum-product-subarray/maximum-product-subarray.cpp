class Solution {
public:
    // all +ve 
    // even -ve ,rest +ve
    // odd -ve, res +ve in this case if it is -ve check for left and right
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre=1,suff=1;
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            pre=pre*nums[i];
            suff=suff*nums[n-i-1];
            res=max(res,max(pre,suff));
            if(pre==0) pre=1;
            if(suff==0) suff=1;
        }
        return res;
    }
};