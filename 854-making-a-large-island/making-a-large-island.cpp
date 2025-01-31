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
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        // int m=grid[0].size();
        
        // vector<vector<int>>vis(n,vector<int>(n,0));

        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int node=row*n+col;
                int drow[]={1,0,-1,0};
                int dcol[]={0,1,0,-1};
                for(int x=0;x<4;x++){
                    int adjr=row+drow[x];
                    int adjc=col+dcol[x];
                    if(adjr>=0 && adjr<n && adjc>=0 && adjc<n){
                        if(grid[adjr][adjc]==1){
                            int newnode=adjr*n+adjc;
                            ds.unionbysize(node,newnode);
                        }
                    }
                }
            }
        }

        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    int drow[]={1,0,-1,0};
                    int dcol[]={0,1,0,-1};
                    set<int>components;
                    for(int x=0;x<4;x++){
                        int adjr=row+drow[x];
                        int adjc=col+dcol[x];
                        if(adjr>=0 && adjr<n && adjc>=0 && adjc<n){
                            if(grid[adjr][adjc]==1){
                                components.insert(ds.findupar(adjr*n+adjc));
                            }
                        }
                    } 
                    int sizeTotal=1;

                    for(auto it:components){
                        sizeTotal+=ds.size[it];
                    }
                    ans=max(ans,sizeTotal);
                }
                else{
                    continue;
                }
            }
        }
        for(int x=0;x<n;x++){
            ans=max(ans,ds.size[ds.findupar(x)]);
        }
        return ans;
    }
};