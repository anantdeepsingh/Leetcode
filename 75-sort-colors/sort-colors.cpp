class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0,cnt1=0,cnt2=0;
        for(auto &it:nums){
            if(it==0){
                cnt0++;
            }
            if(it==1){
                cnt1++;
            }
            if(it==2){
                cnt2++;
            }
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt0>0){
                nums[i]=0;
                cnt0--;
            }
            else if(cnt1>0){
                nums[i]=1;
                cnt1--;
            }
            else if(cnt2>0){
                nums[i]=2;
                cnt2--;
            }
        }

    }
};