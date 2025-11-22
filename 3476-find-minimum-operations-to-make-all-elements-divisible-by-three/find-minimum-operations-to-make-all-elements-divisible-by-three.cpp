class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int x=0;x<n;x++){
            if(nums[x]%3==1){
                ans+=1;
            }
            else if(nums[x]%3==2){
                ans+=1;
            }
        }
        return ans;
    }
};