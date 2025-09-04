class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>dq;
        int n=nums.size();
        deque<int>maxdq;
        deque<int>mindq;
        int ans=0;
        int l=0,r=0;
        while(r<n){
            // maxdq maxi at front
            while(!maxdq.empty() && nums[r]>maxdq.back()) maxdq.pop_back();
            // mindq mini at front
            while(!mindq.empty() && nums[r]<mindq.back()) mindq.pop_back();

            maxdq.push_back(nums[r]);
            mindq.push_back(nums[r]);

            while(l<r && abs(maxdq.front()-mindq.front())>limit){
                if(nums[l]==maxdq.front()) maxdq.pop_front();
                if(nums[l]==mindq.front()) mindq.pop_front();
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};