class Solution {
public:
    const int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>prefix(n,0);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }

        for(int i=0;i<n;i++){
            prefix[i]%=2;
        }
        long long tcnt=1ll*n*(n+1);
        tcnt=tcnt/2;
        tcnt=tcnt%mod;
        int cnt=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int key=prefix[i];
            if(key==0){
                cnt=(cnt+1)%mod;
            }
            if(mp.count(key)){
                cnt=(cnt+mp[key])%mod;
            }
            mp[key]++;
        }

        return (tcnt-cnt+mod)%mod;

    }
};