#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        ll ans=0ll;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }
            else{
                ans+=(1ll*(cnt)*(cnt+1))/2;
                cnt=0;
            }
        }
        ans+=(1ll*(cnt)*(cnt+1))/2;
        return ans;
    }
};