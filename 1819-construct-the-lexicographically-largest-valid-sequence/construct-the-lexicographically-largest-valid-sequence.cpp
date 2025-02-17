class Solution {
public:
    vector<vector<int>>res;
    bool solve(int ind,vector<int>&ans,vector<int>&used,int n){
        while(ind<(2*n-1) && ans[ind]!=0){
            ind++;
        }
        if(ind==(2*n-1)){
            return true;
        }

        for(int i=n;i>=1;i--){
            if(used[i]) continue;
            if(i==1){
                ans[ind]=1;
                used[i]=1;
                if(solve(ind+1,ans,used,n)) return true;
                ans[ind]=0;
                used[i]=0;
            }
            else{
                int nextInd=ind+i;
                if(nextInd<(2*n-1) && ans[nextInd]==0){
                    ans[ind]=i;
                    ans[nextInd]=i;
                    used[i]=1;
                    if(solve(ind+1,ans,used,n)) return true;
                    ans[ind]=0;
                    ans[nextInd]=0;
                    used[i]=0;
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>ans(2*n-1,0);
        vector<int>used(n+1,0);
        solve(0,ans,used,n);
        return ans;
    }

};