class DisjointSet{
    vector<int>par,size;
public:
    DisjointSet(int n){
       par.resize(n+1);
       size.resize(n+1);
       for(int i=0;i<=n;i++){
        par[i]=i;
       }
    }
    int findupar(int u){
       if(par[u]==u) return u;
       return par[u]=findupar(par[u]);
    }
    void unionbysize(int u,int v){
        int upu=findupar(u);
        int upv=findupar(v);
        if(upu==upv)return;
        if(size[upu]>size[upv]){
        par[upv]=upu;
        size[upu]+=size[upv];
        }
        else{
        par[upu]=upv;
        size[upv]+=size[upu];
        }
    }
};
class Solution {
public:
    bool static Cmp(vector<int>&a,vector<int>&b){
        return a[0]>b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet ds1(n);
        DisjointSet ds2(n);
        sort(edges.begin(),edges.end(),Cmp);
        int ans=0;
        for(auto &it:edges){
            if(it[0]==3){
                int u=it[1];
                int v=it[2];
                if(ds1.findupar(u)!=ds1.findupar(v)){
                    ds1.unionbysize(u,v);
                    ds2.unionbysize(u,v);
                }
                else{
                    ans++;
                }
            }
            else if(it[0]==1){
                int u=it[1];
                int v=it[2];
                if(ds1.findupar(u)!=ds1.findupar(v)){
                    ds1.unionbysize(u,v);
                }
                else{
                    ans++;
                }
            }
            else{
                int u=it[1];
                int v=it[2];
                if(ds2.findupar(u)!=ds2.findupar(v)){
                    ds2.unionbysize(u,v);
                }
                else{
                    ans++;
                }
            }
        }


        map<int,int>mp;
        for(int i=1;i<=n;i++){
            int par=ds1.findupar(i);
            mp[par]++;
        }

        if(mp.size()>1) return -1;
        mp.clear();

        for(int i=1;i<=n;i++){
            int par=ds2.findupar(i);
            mp[par]++;
        }

        if(mp.size()>1) return -1;
        return ans;
    }
};