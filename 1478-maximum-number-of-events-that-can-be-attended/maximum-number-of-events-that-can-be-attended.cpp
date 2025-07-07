class Solution {
public:
    bool static Cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        int start=events[0][0];
        int last=events[n-1][1];
        priority_queue<int,vector<int>,greater<int>>pq;
        int j=0;
        int ans=0;
        for(int i=start;i<=1e5;i++){
            while(j<n && events[j][0]<=i){
                pq.push(events[j][1]);
                j++;
            }

            while(!pq.empty() && pq.top()<i){
                pq.pop();
            }

            if(!pq.empty()){
                pq.pop();
                ans++;
            }

        }
        return ans;
    }
};