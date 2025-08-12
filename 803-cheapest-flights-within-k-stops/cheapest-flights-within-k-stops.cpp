#define t tuple<int,int,int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<t,vector<t>,greater<t>>q;

        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        q.push({0,0,src});
        vector<int>cost(n,INT_MAX);
        cost[src]=0;
        while(!q.empty()){
            auto [stops,price,node]=q.top();
            q.pop();
            if(stops>=(k+1)) continue;
            for(auto &it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                if(price+wt<cost[adjNode]){
                    cost[adjNode]=price+wt;
                    q.push({stops+1,price+wt,adjNode});
                }
            }
        }

        return cost[dst]==INT_MAX?-1:cost[dst];
    }
};