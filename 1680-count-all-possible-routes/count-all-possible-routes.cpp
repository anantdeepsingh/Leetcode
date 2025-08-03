const int mod=1e9+7;
class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int fuel,vector<int>& locations,int finish){
        int n=locations.size();

        if(dp[i][fuel]!=-1) return dp[i][fuel];
        int ans=0;
        bool flag=false;
        for(int j=0;j<n;j++){
            if(j==i) continue;

            int fuelNeeded=abs(locations[i]-locations[j]);
            
            if(fuelNeeded<=fuel && j==finish){
                flag=true;
                ans=(ans%mod+1%mod+solve(j,fuel-fuelNeeded,locations,finish)%mod)%mod;
            }
            else if(fuelNeeded<=fuel){
                flag=true;
                ans=(ans%mod+solve(j,fuel-fuelNeeded,locations,finish)%mod)%mod;
            }
            
        }

        if(flag==false) return 0;

        return dp[i][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int ans=0;
        int n=locations.size();
        dp.assign(n,vector<int>(fuel+1,-1));
        if(start==finish) {
            ans++;
        }
        ans=(ans%mod+solve(start,fuel,locations,finish)%mod)%mod;
        return ans;
    }
};

