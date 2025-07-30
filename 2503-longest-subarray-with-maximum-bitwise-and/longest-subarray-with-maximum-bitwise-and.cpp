class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        int r=0;
        int maxLen=0;
        int cons=0;
        while(r<n){
            if(nums[r]==mx){
                cons++;
            }
            else{
                maxLen=max(maxLen,cons);
                cons=0;
            }
            r++;
        }
        maxLen=max(maxLen,cons);
        return maxLen;
    }
};


// 0 0 1
// 0 1 0
// 0 1 1 
// 0 1 1
// 0 1 0
// 0 1 0

// and is a decrementing assses