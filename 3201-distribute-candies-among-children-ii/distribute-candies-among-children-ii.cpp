class Solution {
public:
    long long distributeCandies(int n, int limit) {
        vector<long long>count(2*limit+1,0ll);
        for(int i=0;i<=limit;i++){
            count[i]=1ll*i+1ll*1;
        }
        int k=limit;
        for(int i=limit+1;i<=2*limit;i++){
            count[i]=k;
            k--;
        }


        long long ans=0;

        for(int i=0;i<=limit;i++){
            long long left=1ll*n-1ll*i;
            if(left>2*limit) continue;
            if(left>=0) ans+=1ll*count[n-i];
        }

        return ans;
    }
};