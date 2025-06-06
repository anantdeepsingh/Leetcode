#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<vector<int>,int>mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll rem=1ll*target-1ll*nums[i]-1ll*nums[j];
                int l=j+1,r=n-1;
                while(l<r){
                    ll sum=1ll*nums[l]+1ll*nums[r];
                    if(sum==rem){
                        vector<int>temp={nums[i],nums[j],nums[l],nums[r]};
                        mp[temp]++;
                        l++;
                        r--;
                    }
                    else if(sum>rem){
                        r--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            ans.push_back(it.first);
        }
        return ans;
    }
};