class Solution {
public:
    vector<int> compute(int node,vector<vector<int>>&graph,int n){
        vector<int>dist(n,1e8);
        queue<int>q;
        q.push(node);
        dist[node]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                if(dist[it]>dist[node]+1){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                graph[i].push_back(edges[i]);
            }
        }

        vector<int>dist1=compute(node1,graph,n);
        vector<int>dist2=compute(node2,graph,n);

        int ans=1e8;
        int res;

        // for(int i=0;i<n;i++){
        //     cout<<dist1[i]<<" "<<dist2[i]<<endl;
        // }
        for(int i=0;i<n;i++){
            // cout<<ans<<" "<<max(dist1[i],dist2[i])<<endl;
            if(ans>max(dist1[i],dist2[i])){
                ans=max(dist1[i],dist2[i]);
                res=i;
            }
        }

        return ans==1e8?-1:res;
    }
};