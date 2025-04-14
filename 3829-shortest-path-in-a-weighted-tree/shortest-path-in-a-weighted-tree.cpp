vector<array<int,2>> a[100005];
long long seg[800005],lazy[800005],st[100005],ed[100005],sum[100005];
int timer;

void euler(int node,int par=-1){
    st[node]=timer++;
    for(auto edge: a[node]){
        if(edge[0]==par) continue;
        sum[edge[0]]=sum[node]+edge[1];
        euler(edge[0],node);
    }
    ed[node]=timer++;
}

void push(int id, int l, int r) {
    if (lazy[id] != 0) {
        seg[id] += (r - l + 1) * lazy[id];
        if (l != r) {
            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
        }
        lazy[id] = 0;
    }
}

void update(int id, int l, int r, int ql, int qr, int val) {
    push(id, l, r);
    if (r < ql || l > qr) return;
    if (ql <= l && r <= qr) {
        lazy[id] += val;
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, ql, qr, val);
    update(id * 2 + 1, mid + 1, r, ql, qr, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

long long get(int id, int l, int r, int idx) {
    push(id, l, r);
    if (l == r) return seg[id];
    int mid = (l + r) / 2;
    if (idx <= mid)
        return get(id * 2, l, mid, idx);
    else
        return get(id * 2 + 1, mid + 1, r, idx);
}

class Solution {
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        map<array<int,2>,int> weights;
        for(int i=0;i<=n;i++){
            a[i].clear();
            st[i]=ed[i]=sum[i]=0;
        }
        for(int i=0;i<=8*n;i++) seg[i]=lazy[i]=0;
        for(auto u: edges){
            weights[{u[0],u[1]}]=weights[{u[1],u[0]}]=u[2];
            a[u[0]].push_back({u[1],u[2]});
            a[u[1]].push_back({u[0],u[2]});
        }
        timer=1;
        euler(1);
        vector<int> ans;
        for(auto query: queries){
            if(query[0]==1){
                int u=query[1],v=query[2];
                if(st[u]>st[v]) swap(u,v);
                update(1,0,2*n,st[v],ed[v],query[3]-weights[{u,v}]);
                weights[{u,v}]=weights[{v,u}]=query[3];
            }
            else  ans.push_back(sum[query[1]]+get(1,0,2*n,st[query[1]]));
        }
        return ans;
    }
};