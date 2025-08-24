class DisjointSet {
public:
    vector<int> par, size;
    DisjointSet(int n) {
        par.resize(n+1);
        size.resize(n+1, 1);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int findupar(int u) {
        if (par[u] == u) return u;
        return par[u] = findupar(par[u]);
    }

    void unionbysize(int u, int v) {
        int upu = findupar(u);
        int upv = findupar(v);
        if (upu == upv) return;
        if (size[upu] >= size[upv]) {
            size[upu] += size[upv];
            par[upv] = upu;
        } else {
            size[upv] += size[upu];
            par[upu] = upv;
        }
    }
};

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        DisjointSet ds(n);

        stack<int> st;

        // Pass 1: prev_greater style (left -> right)
        
        for(int i=n-1;i>=0;i--){
            int next=i;
            if(!st.empty()) next=st.top();
            while(!st.empty() && nums[i]>nums[st.top()]){
                ds.unionbysize(i,st.top());
                st.pop();
            }
            if(nums[i]<nums[next]) st.push(i);
            else st.push(next);
        }

        while (!st.empty()) st.pop();

        // Pass 2: next_smaller style (right -> left)
        for(int i=0;i<n;i++){
            int prev=i;
            if(!st.empty()) prev=st.top();

            while(!st.empty() && nums[i]<nums[st.top()]){
                ds.unionbysize(i,st.top());
                st.pop();
            }
            if(nums[i]>nums[prev]) st.push(i);
            else st.push(prev);
        }

        // Compute max value in each component
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            int u = ds.findupar(i);
            mp[u] = max(mp[u], nums[i]);
        }

        // Build answer
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int u = ds.findupar(i);
            ans[i] = mp[u];
        }
        return ans;
    }
};


// [30,21,5,35,24]
