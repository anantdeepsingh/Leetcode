class Solution {
public:
    vector<int>dp;
    int solve(int i,vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        int n=startTime.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int op1=solve(i+1,startTime,endTime,profit);
        int ind=lower_bound(startTime.begin(),startTime.end(),endTime[i])-startTime.begin();
        int op2=profit[i]+solve(ind,startTime,endTime,profit);

        return dp[i]=max(op1,op2);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({startTime[i],i});
        }

        sort(v.begin(),v.end());
        auto a=startTime;
        auto b=endTime;
        auto c=profit;
        for(int i=0;i<n;i++){
            int ind=v[i].second;
            a[i]=startTime[ind];
            b[i]=endTime[ind];
            c[i]=profit[ind];
        }
        dp.assign(n,-1);
        return solve(0,a,b,c);
    }
};