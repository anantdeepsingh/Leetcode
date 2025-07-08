const int mod=1e9+7;
class Solution {
public:
    const int MOD = 1e9 + 7;
    const int N = 1e5 + 5;
    vector<long long>fact,invFact;
    long long modPow(long long x, long long y, long long mod) {
    long long res = 1;
    x %= mod;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
    }

    void precompute() {
    fact.resize(N);
    invFact.resize(N);
    fact[0] = invFact[0] = 1ll;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[N - 1] = modPow(fact[N - 1], MOD - 2, MOD);  // Fermat's inverse
    for (int i = N - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
    }
    long long nCr(int n, int r) {
    if (r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        precompute();
        vector<vector<int>>adj(n+1);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        q.push(0);
        int last;
        int lev=0;
        vector<int>vis(n+1,0);
        vis[0]=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int node=q.front();
                last=node;
                q.pop();
                for(auto &it:adj[node]){
                    if(vis[it]==0){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            lev++;
        }

        int ht=lev-1;
        int ans=0;
        for(int i=1;i<=ht;i+=2){
            ans=(ans%mod+nCr(ht,i)%mod)%mod;
        }
        return ans;
    }
};