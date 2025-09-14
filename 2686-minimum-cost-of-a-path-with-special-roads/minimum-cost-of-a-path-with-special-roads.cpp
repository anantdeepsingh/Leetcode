#define pi pair<int,int>
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        // priority_queue<pi,vector<pi>,greater<pi>>pq;
        int n=specialRoads.size();
        map<pair<int,int>,int>mp1;
        map<int,pair<int,int>>mp2;
        int c=0;
        if(mp1.count({start[0],start[1]})==0){
            mp2[c]={start[0],start[1]};
            mp1[{start[0],start[1]}]=c;
            c++;
        }
        for(int i=0;i<n;i++){
            int u=specialRoads[i][0];
            int v=specialRoads[i][1];
            int x=specialRoads[i][2];
            int y=specialRoads[i][3];

            if(mp1.count({u,v})==0){
                mp1[{u,v}]=c;
                mp2[c]={u,v};
                c++;
            }

            if(mp1.count({x,y})==0){
                mp1[{x,y}]=c;
                mp2[c]={x,y};
                c++;
            }


        }

        if(mp1.count({target[0],target[1]})==0){
            mp2[c]={target[0],target[1]};
            mp1[{target[0],target[1]}]=c;
            c++;
        }
        vector<vector<pair<int,int>>>adj(c);
        for(int i=0;i<c;i++){
            for(int j=i+1;j<c;j++){
                adj[i].push_back({j,(abs(mp2[i].first-mp2[j].first)+abs(mp2[i].second-mp2[j].second))});
                adj[j].push_back({i,(abs(mp2[i].first-mp2[j].first)+abs(mp2[i].second-mp2[j].second))});
            }
        }

       for(int i=0;i<n;i++){
            int u = specialRoads[i][0];
            int v = specialRoads[i][1];
            int x = specialRoads[i][2];
            int y = specialRoads[i][3];
            int wt = specialRoads[i][4];

            int node1 = mp1[{u,v}];
            int node2 = mp1[{x,y}];

            for(auto &it:adj[node1]){
                if(it.first==node2){
                    it.second=min(it.second,wt);
                }
            }
        }


        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({0,0});
        vector<int>dist(c,1e8);
        dist[0]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                if(dist[adjNode]>wt+d){
                    dist[adjNode]=wt+d;
                    pq.push({wt+d,adjNode});
                }
            }
        }

        return dist[mp1[{target[0],target[1]}]];
    }
};