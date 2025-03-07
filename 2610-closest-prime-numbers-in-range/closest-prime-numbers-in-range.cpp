class Solution {
public:
    vector<int> sieve(int n){
        vector<int>prime(n+1,1);
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=2*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
    vector<int>ans;
    for(int i=2;i<=n;i++){
            if(prime[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>prime=sieve(1000050);

        vector<int>v;
        for(auto it:prime){
            if(it>=left && it<=right){
                v.push_back(it);
            }
        }

        if(v.size()<2){
            return {-1,-1};
        }
        int v1=0,v2=0;
        int maxi=INT_MAX;
        for(int i=1;i<v.size();i++){
            int diff=v[i]-v[i-1];
            if(diff<maxi){
                maxi=diff;
                v1=v[i-1];
                v2=v[i];
            }
        }

        return {v1,v2};
    }
};