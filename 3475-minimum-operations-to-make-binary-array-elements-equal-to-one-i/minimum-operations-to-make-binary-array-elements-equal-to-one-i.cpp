class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<=n-3;i++){
            if(nums[i]==1) continue;
            nums[i]=1-nums[i];
            nums[i+1]=1-nums[i+1];
            nums[i+2]=1-nums[i+2];
            cnt++;
        }


        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }

        if((int)mp.size()==1) return cnt;
        return -1;
    }
};