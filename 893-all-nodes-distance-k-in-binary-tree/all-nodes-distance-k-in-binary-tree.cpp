/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>>adj(501);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                int u=node->val;
                int v=node->left->val;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            if(node->right){
                q.push(node->right);
                int u=node->val;
                int v=node->right->val;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }


        int node=target->val;
        vector<int>ans;
        queue<pair<int,int>>pq;
        pq.push({node,0});
        vector<int>vis(501,0);
        vis[node]=1;
        while(!pq.empty()){
            int node=pq.front().first;
            int lev=pq.front().second;
            pq.pop();
            if(lev==k){
                ans.push_back(node);
            }

            if(lev>k) break;
            for(auto &it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    pq.push({it,lev+1});
                }
            }
        }

        return ans;
    }
};