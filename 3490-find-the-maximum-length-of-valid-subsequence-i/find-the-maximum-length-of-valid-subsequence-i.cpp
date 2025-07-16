class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int flag1=0,flag2=1;
        int cntEven=0,cntOdd=0,cnt1=0,cnt2=0;
        for(auto &i:nums){
            if(i%2==0){
                cntEven++;
            }
            else{
                cntOdd++;
            }
            if(i%2==flag1){
                cnt1++;
                flag1=!flag1;
            }
            if(i%2==flag2){
                cnt2++;
                flag2=!flag2;
            }
        }

        return max({cntEven,cntOdd,cnt1,cnt2});
    }
};