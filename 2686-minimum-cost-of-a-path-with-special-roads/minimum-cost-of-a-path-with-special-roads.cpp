#define pi pair<int,int>
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int n = specialRoads.size();
        map<pair<int,int>,int> mp1;  // coordinate -> node index
        map<int,pair<int,int>> mp2;  // node index -> coordinate
        int c = 0;

        // add start
        if(mp1.count({start[0], start[1]}) == 0){
            mp2[c] = {start[0], start[1]};
            mp1[{start[0], start[1]}] = c;
            c++;
        }

        // add special road endpoints
        for(int i=0;i<n;i++){
            int u = specialRoads[i][0];
            int v = specialRoads[i][1];
            int x = specialRoads[i][2];
            int y = specialRoads[i][3];

            if(mp1.count({u,v})==0){
                mp1[{u,v}] = c;
                mp2[c] = {u,v};
                c++;
            }
            if(mp1.count({x,y})==0){
                mp1[{x,y}] = c;
                mp2[c] = {x,y};
                c++;
            }
        }

        // add target
        if(mp1.count({target[0], target[1]})==0){
            mp2[c] = {target[0], target[1]};
            mp1[{target[0], target[1]}] = c;
            c++;
        }

        // adjacency list
        vector<vector<pair<int,int>>> adj(c);

        // connect all nodes with Manhattan distance (both directions)
        for(int i=0;i<c;i++){
            for(int j=i+1;j<c;j++){
                int dist = abs(mp2[i].first - mp2[j].first) + abs(mp2[i].second - mp2[j].second);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        // add special roads (directed edges)
        for(int i=0;i<n;i++){
            int u = mp1[{specialRoads[i][0], specialRoads[i][1]}];
            int v = mp1[{specialRoads[i][2], specialRoads[i][3]}];
            int wt = specialRoads[i][4];
            adj[u].push_back({v, wt});
        }

        // Dijkstra
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int> dist(c, 1e9);
        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if(d > dist[node]) continue; // skip stale entry

            for(auto &it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dist[adjNode] > d + wt){
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist[mp1[{target[0], target[1]}]];
    }
};
