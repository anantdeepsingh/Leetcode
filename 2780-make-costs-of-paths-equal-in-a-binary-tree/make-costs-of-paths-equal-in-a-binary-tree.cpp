class Solution {
public:
    int ans=0;
    int dfs(int node,vector<int>&cost){
        if(node>=cost.size()) return 0;
        int a=dfs(2*node+1,cost);
        int b=dfs(2*node+2,cost);
        ans+=abs(b-a);
        return cost[node]+max(a,b);
    }
    int minIncrements(int n, vector<int>& cost) {
        dfs(0,cost);
        return ans;
    }
};