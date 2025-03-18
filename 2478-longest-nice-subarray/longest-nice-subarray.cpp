class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int mask=0;
        int res=0;
        while(r<n){
           
            while((nums[r]&mask)!=0){
                mask=mask^nums[l];
                l++;
            }

            mask=mask|nums[r];
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};