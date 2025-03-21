class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<int,string>nodes;
        map<string,int>names;
        int n=recipes.size();
        for(int i=0;i<n;i++){
            nodes[i]=recipes[i];
            names[recipes[i]]=i;
        }
        vector<int>indegree(n,0);
        // for(int i=0;i<n;i++){
        //     indegree[i]=0;
        // }
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            int k=ingredients[i].size();
            for(int j=0;j<k;j++){
                string t=ingredients[i][j];
                if(names.count(t)){
                    int u=names[t];
                    int v=i;
                    adj[u].push_back(v);
                    indegree[v]++;
                }
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>order;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            order.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        set<string>s;
        for(auto it:supplies){
            s.insert(it);
        }
        vector<string>ans;
        for(auto it:order){
            int ind=it;
            int k=ingredients[ind].size();
            bool flag=true;
            for(int i=0;i<k;i++){
                string t=ingredients[ind][i];
                if(s.find(t)==s.end()){
                    flag=false;
                    break;
                }
            }

            if(flag){
                s.insert(nodes[ind]);
                ans.push_back(nodes[ind]);
            }
        }
        return ans;
    }
};