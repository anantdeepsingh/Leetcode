const int mod=1e9+7;
#define t tuple<long long,int>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>>adj(n);
        for(auto &edg:roads){
            int u=edg[0];
            int v=edg[1];
            long long wt=edg[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<long long>dist(n,LLONG_MAX);
        priority_queue<t,vector<t>,greater<t>>pq;
        pq.push({0ll,0});
        dist[0]=0ll;
        vector<long long>ways(n,0ll);
        ways[0]=1;
        while(!pq.empty()){
            auto[time,node]=pq.top();
            pq.pop();

            if(node==n-1){
                break;
            }
            for(auto &&it:adj[node]){
                int v=it.first;
                long long wt=it.second;
                if(dist[v]>time+wt){
                    pq.push({1ll*time+1ll*wt,v});
                    dist[v]=1ll*time+1ll*wt;
                    ways[v]=ways[node];
                }
                else if(dist[v]==time+wt){
                    ways[v]=(ways[v]%mod+ways[node]%mod)%mod;
                }
            }
        }

        return ways[n-1];
        
    }
};