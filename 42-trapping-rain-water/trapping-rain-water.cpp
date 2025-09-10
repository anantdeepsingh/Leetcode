class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int mini=height[0];
        int sum=height[0];
        int ans=0;
        int prev=0;
        for(int i=1;i<n;i++){
            if(height[i]>=mini){
                ans+=(i-prev)*mini-sum;
                sum=0;
                prev=i;
                mini=height[i];
            }
            sum+=height[i];
        }
        // cout<<ans<<endl;
        mini=height[n-1];
        sum=height[n-1];
        prev=n-1;
        for(int i=n-2;i>=0;i--){
            if(height[i]>mini){
                // cout<<(prev-i)*mini-sum<<endl;
                ans+=(prev-i)*mini-sum;
                sum=0;
                prev=i;
                mini=height[i];
            }
            sum+=height[i];
        }
        return ans;
    }
};