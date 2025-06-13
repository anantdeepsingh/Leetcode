class Solution {
public:
    bool check(int mid,int p,vector<int>&nums){
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=mid){
                cnt++;
                i++;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        cout<<maxi<<" "<<mini<<endl;
        sort(nums.begin(),nums.end());
        int low=0,high=maxi-mini;
        int ans=0;
        cout<<high<<endl;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,p,nums)){
                ans=mid;
                cout<<ans<<endl;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};