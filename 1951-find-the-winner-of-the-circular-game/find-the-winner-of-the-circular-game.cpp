class Solution {
public:
    int ans;
    void solve(int start,int k,vector<int>&v){
        if(v.size()==1){
            ans=v[0];
            return;
        }
        int nind=(start+k)%v.size();
        v.erase(v.begin()+nind);
        solve(nind,k,v);
    }
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        solve(0,k-1,v);
        return ans;
    }
};