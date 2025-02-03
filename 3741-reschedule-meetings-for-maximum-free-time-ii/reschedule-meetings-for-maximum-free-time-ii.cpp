class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& st, vector<int>& et) {
        int n = st.size();
        vector<int>pre(n+1,0),suf(n+1,0);

        int end = 0, ans = st[0];

        for(int i=0;i<n;i++){
            int gap = st[i]-end;
            ans=max(ans,gap);
            end=et[i];
            pre[i+1]=max(pre[i],gap);
        }

        ans=max(ans,eventTime-et[n-1]);

        int start = eventTime;

        for(int i=(n-1);i>=0;i--){
            int gap = start-et[i];
            start = st[i];
            suf[i]=max(suf[i+1],gap);
        }

        for(int i=0;i<n;i++){
            int prevend = (i==0?0:et[i-1]);
            int nextstart = (i==(n-1)?eventTime:st[i+1]);

            int gap = nextstart-prevend;
            int len = et[i]-st[i];
            if((pre[i]>= len) || (suf[i+1]>=len)){
                ans=max(ans,gap);
            }
            else{
                ans=max(ans,gap-len);
            }
        }

        return ans;

    }
};