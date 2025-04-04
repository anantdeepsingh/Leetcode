/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool getPath(TreeNode* root, TreeNode * p, vector<TreeNode*>&ans){
        if(root==NULL) return false;
        ans.push_back(root);
        if(root->val==p->val) return true;
        if(getPath(root->left,p,ans) || getPath(root->right,p,ans)) return true;

        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL || root==p || root==q){
        return root;
       }
       TreeNode* left=lowestCommonAncestor(root->left,p,q);
       TreeNode* right=lowestCommonAncestor(root->right,p,q);
       if(left==NULL){
        return right;
       }
       else if(right==NULL){
        return left;
       }
       else{
        return root;
       }
    }
    int compute(TreeNode* root){
        if(root==NULL) return 0;

        int lh=compute(root->left);
        int rh=compute(root->right);

        int t=1+max(lh,rh);

        return t;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int ht=compute(root);

        vector<TreeNode*>v;

        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                int lev=q.front().second;
                q.pop();
                if(lev==ht){
                    v.push_back(node);
                }

                if(node->left){
                    q.push({node->left,lev+1});
                }

                if(node->right){
                    q.push({node->right,lev+1});
                }
            }
        }


        if(v.size()==1){
            return v[0];
        }


        return lowestCommonAncestor(root,v[0],v[v.size()-1]);
    }
};