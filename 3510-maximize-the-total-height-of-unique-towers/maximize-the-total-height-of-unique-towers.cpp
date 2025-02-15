#define ll long long
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        
        sort(maximumHeight.begin(),maximumHeight.end());

       int n=maximumHeight.size();
       int prev=INT_MAX;
       ll ans=0;
       for(int i=n-1;i>=0;i--){
        if(maximumHeight[i]<prev){
            ans+=1ll*maximumHeight[i];
            prev=maximumHeight[i];
        }
        else{
            ans+=1LL*(prev-1);
            prev=prev-1;
        }

        if(prev==0) return -1;
       }

       return ans;
    }
};