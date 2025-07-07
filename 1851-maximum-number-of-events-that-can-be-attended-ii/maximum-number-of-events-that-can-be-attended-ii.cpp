class Solution {
public:
    int find(int val,vector<vector<int>>& events){
        int n=events.size();
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(events[mid][0]>val){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<vector<int>>dp;
    int f(int i,int k,vector<vector<int>>& events){
        
        int n=events.size();

        if(k==0) return 0;
        if(i==n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        // not pick

        int op1=f(i+1,k,events);
        // pick 
        int op2=0;
        int j=find(events[i][1],events);
        op2=events[i][2]+f(j,k-1,events);


        return dp[i][k]=max(op1,op2);

    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());

        int n=events.size();
        dp.assign(n,vector<int>(k+1,-1));
        return f(0,k,events);
    }
};