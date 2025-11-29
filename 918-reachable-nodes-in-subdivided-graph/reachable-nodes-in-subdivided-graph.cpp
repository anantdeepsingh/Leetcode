#define pi pair<int,int>
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>>adj(n);
        if(edges.size()==0) return 1;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int cnt=it[2];
            adj[u].push_back({v,cnt});
            adj[v].push_back({u,cnt});
        }
        vector<int>dist(n,1e8);
        map<pair<int,int>,int>mp;
        dist[0]=0;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(d>dist[node]) continue;
            for(auto &it:adj[node]){
                int eWt=it.second;
                int adjNode=it.first;
                mp[{node,adjNode}]+=min(eWt,max(0,maxMoves-d));
                if(d+(eWt+1)<dist[adjNode] && d+(eWt+1)<=maxMoves){
                    dist[adjNode]=d+(eWt+1);
                    pq.push({d+(eWt+1),adjNode});
                }
            }
        }
        int ans=0;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int cnt=it[2];

            int v1=mp[{u,v}];
            int v2=mp[{v,u}];
            ans+=min(cnt,v1+v2);
        }

        for(int i=0;i<n;i++){
            if(dist[i]<=maxMoves) ans++;
        }

        return ans;
    }
};