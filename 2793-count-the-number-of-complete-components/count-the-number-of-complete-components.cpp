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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        DisjointSet ds(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            indegree[u]++;
            indegree[v]++;
        }

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.findupar(u)!=ds.findupar(v)){
                ds.unionbysize(u,v);
            }
        }
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            int p=ds.par[i];
            mp[p].push_back(i);
        }
        int cnt=0;
        for(auto it:mp){
            vector<int>nodes=it.second;
            int size=nodes.size();
            bool flag=true;
            for(auto it:nodes){
                if(indegree[it]!=(size-1)){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
        }
        return cnt;
    }
};