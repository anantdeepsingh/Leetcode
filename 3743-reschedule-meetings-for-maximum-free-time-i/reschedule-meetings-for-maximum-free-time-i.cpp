class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>dist;
        dist.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            int gap=startTime[i]-endTime[i-1];
            dist.push_back(gap);
        }
        dist.push_back(eventTime-endTime[n-1]);
        int l=0,r=0;
        int maxTime=0;
        int currTime=0;
        int sz=dist.size();
        while(r<sz){
            currTime+=dist[r];
            if(r-l+1>(k+1)){
                currTime-=dist[l];
                l++;
            }
            if(r-l+1==(k+1)){
                maxTime=max(maxTime,currTime);
            }
            r++;
        }

        return maxTime;
    }
};