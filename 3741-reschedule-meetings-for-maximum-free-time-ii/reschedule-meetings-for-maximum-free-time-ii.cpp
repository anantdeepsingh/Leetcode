class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>dist;
        int k=1;
        int ans=startTime[0];
        dist.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            int gap=startTime[i]-endTime[i-1];
            ans=max(ans,gap);
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

        ans=max(ans,maxTime);
        ans=max(ans,eventTime-endTime[n-1]);
        vector<int>maxGap(n,0);

        maxGap[n-1]=eventTime-endTime[n-1];
        for(int i=n-2;i>=0;i--){
            int diff=startTime[i+1]-endTime[i];
            maxGap[i]=max(diff,maxGap[i+1]);
        }

        if(maxGap[1]>=endTime[0]-startTime[0]){
            ans=max(ans,startTime[1]);
        }
        // for(int i=1;i<n-1;i++){
        //     if(maxGap[i+1]>=endTime[i]-startTime[i]){
        //         ans=max(ans,startTime[i+1]-endTime[i]);
        //     }
        // }

        vector<int>maxleft(n,0);
        maxleft[0]=startTime[0];

        for(int i=1;i<n;i++){
            int diff=startTime[i]-endTime[i-1];
            maxleft[i]=max(maxleft[i-1],diff);
        }
        // for(auto it:maxGap){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:maxleft){
        //     cout<<it<<" ";
        // }

         for(int i=1;i<n-1;i++){
            if(maxGap[i+1]>=endTime[i]-startTime[i]){
                ans=max(ans,startTime[i+1]-endTime[i-1]);
            }
            if(maxleft[i-1]>=endTime[i]-startTime[i]){
                ans=max(ans,startTime[i+1]-endTime[i-1]);
            }
        }


        if(maxleft[n-2]>=endTime[n-1]-startTime[n-1]){
            ans=max(ans,eventTime-endTime[n-2]);
        }
        return ans;
    }
};