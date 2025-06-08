class Solution {
public:
    const int mod=1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>maxq;
        deque<int>minq;
        vector<int> dp(n + 1, 0); dp[0] = 1;
        vector<int> acc(n + 2, 0); acc[1] = 1;
        for(int i=0,j=0;i<n;i++){
            while(!maxq.empty() && nums[i]>nums[maxq.back()]){
                maxq.pop_back();
            }
            maxq.push_back(i);
            while(!minq.empty() && nums[i]<nums[minq.back()]){
                minq.pop_back();
            }
            minq.push_back(i);
            while(nums[maxq.front()]-nums[minq.front()]>k){
                j++;
                if(minq.front()<j){
                    minq.pop_front();
                }
                if(maxq.front()<j){
                    maxq.pop_front();
                }
            }

            dp[i+1]=(acc[i+1]-acc[j]+mod)%mod;
            acc[i+2]=(acc[i+1]+dp[i+1])%mod;
        }

        return dp[n];
    }
};