#define ll long long
class Solution {
public:
    int find(int val,vector<vector<int>>& rides,int n){
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(rides[mid][0]>=val){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<ll>dp;
    ll f(int i,vector<vector<int>>& rides,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        ll op1=1ll*f(i+1,rides,n);
        ll op2=0ll;
        int j=find(rides[i][1],rides,n);
        op2=rides[i][1]-rides[i][0]+rides[i][2]+f(j,rides,n);
        return dp[i]=max(op1,op2);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        int k=rides.size();
        dp.assign(k,-1ll);
        return f(0,rides,k);
    }
};