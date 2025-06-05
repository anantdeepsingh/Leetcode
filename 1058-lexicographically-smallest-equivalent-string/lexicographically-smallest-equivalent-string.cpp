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

    string smallestEquivalentString(string s1, string s2, string b) {
       
        int n=s1.size();
        
        vector<vector<int>>adj(26);
        for(int i=0;i<n;i++){
            int u=s1[i]-'a';
            int v=s2[i]-'a';
            if(u==v) continue;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dist(26);
        for(int i=0;i<26;i++){
            dist[i]=i;
        }
        for(int i=0;i<26;i++){
            vector<int>vis(26,0);
            queue<int>q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                dist[i]=min(dist[i],dist[node]);
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
        }

        string ans="";
        for(int i=0;i<b.size();i++){
            char ch=dist[b[i]-'a']+'a';
            ans+=ch;
        }
        return ans;
    }
};