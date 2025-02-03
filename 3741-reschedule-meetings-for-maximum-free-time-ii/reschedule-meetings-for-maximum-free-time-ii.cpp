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


        // for(auto it:pre){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        ans=max(ans,eventTime-et[n-1]);

        int start = eventTime;

        for(int i=(n-1);i>=0;i--){
            int gap = start-et[i];
            start = st[i];
            suf[i]=max(suf[i+1],gap);
        }


        //  for(auto it:suf){
        //     cout<<it<<" ";
        // }
        cout<<endl;
        for(int i=0;i<n;i++){
            int prevend = (i==0?0:et[i-1]);
            int nextstart = (i==(n-1)?eventTime:st[i+1]);
            // cout<<prevend<<" "<<nextstart<<endl;
            int gap = nextstart-prevend;
            int len = et[i]-st[i];
            // pre[i] mere pehle tak kitna maximum hai 
            // suff[i+1] i+1 se aage kitne maximum 


            // box1   g1 box2  g2  box3

            // box1 tak maxi>=box2 len aa gya toh box2 box1 ke aage chala jayega aur gap g1+g2 ho jayega nhi toh g1+g2-len ho jayega

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