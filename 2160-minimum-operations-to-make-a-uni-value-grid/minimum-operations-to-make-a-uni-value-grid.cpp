class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>a(n*m);
        int ind=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[ind]=grid[i][j];
                int rem=a[ind]%x;
                mp[rem]++;
                ind++;
            }
        }
        if(mp.size()!=1) return -1;
        sort(a.begin(),a.end());
        vector<int>prefix(n*m,0);
        prefix[0]=a[0];

        for(int i=1;i<n*m;i++){
            prefix[i]=prefix[i-1]+a[i];
        }

        int ans=INT_MAX;

        int cnt=abs((prefix[n*m-1]-prefix[0])- ((m*n-1)*a[0]))/x;
        ans=min(ans,cnt);
        for(int i=1;i<n*m-1;i++){
            int cnt=abs(((prefix[n*m-1]-prefix[i]) -(m*n-(i+1))*a[i]))/x;
            cnt+=abs(prefix[i-1]-i*a[i])/x;
            cout<<cnt<<endl;
            ans=min(ans,cnt);
        }
        return ans;
    }
};