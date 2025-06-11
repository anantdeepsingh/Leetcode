class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            if(prefix[i]==k){
                ans++;
            }
            int left=prefix[i]-k;
            if(mp.count(left)){
                ans+=mp[left];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};