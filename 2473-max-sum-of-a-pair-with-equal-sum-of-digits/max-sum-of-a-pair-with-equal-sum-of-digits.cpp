class Solution {
public:
    int sumDigits(int num){
        int sum=0;
        while(num>0){
            int rem=num%10;
            sum+=rem;
            num=num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=INT_MIN;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int sum=sumDigits(nums[i]);
            if(mp.count(sum)){
                maxi=max(maxi,nums[i]+mp[sum]);
                mp[sum]=nums[i];
            }
            else{
                mp[sum]=nums[i];
            }
        }
        return maxi==INT_MIN?-1:maxi;
    }
};