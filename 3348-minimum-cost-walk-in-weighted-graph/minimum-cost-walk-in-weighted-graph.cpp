class DisjointSet{
    public:
    vector<int> rank,size,par;
 
    DisjointSet(int n){
      rank.resize(n+1,0);
      par.resize(n+1);
      size.resize(n+1,1);
      for(int i=0;i<=n;i++){par[i]=i;}
    }
    int findupar(int v){
      if(par[v]==v)return v;
      
      return par[v]=findupar(par[v]);
    }
    
    void unionbyrank(int u,int v){
         int upu=findupar(u);
         int upv=findupar(v);
         if(upu==upv)return;
         
         if(rank[upu]>rank[upv]){
          par[upv]=upu;
         }
         else if(rank[upu]<rank[upv]){
          par[upu]=upv;
         }
         else{
          rank[upu]++;
          par[upv]=upu;
         }
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        DisjointSet ds(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.findupar(u)!=ds.findupar(v)){
                ds.unionbysize(u,v);
            }
        }


        map<int,int>mp;

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(ds.findupar(u)==ds.findupar(v)){
                int parent=ds.findupar(u);
                if(mp.count(parent)){
                    mp[parent]&=w;
                }
                else{
                    mp[parent]=w;
                }
            }
        }


        
        vector<int>res;
        for(auto it:query){
            int u=it[0];
            int v=it[1];

            if(ds.findupar(u)==ds.findupar(v)){
                int parent=ds.findupar(u);
                res.push_back(mp[parent]);
            }
            else{
                res.push_back(-1);
            }
        }
        return res;
    }
};