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
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL || root->val==p->val || root->val==q->val) return root;
        TreeNode* l=lca(root->left,p,q);
        TreeNode* r=lca(root->right,p,q);
        if(l==NULL) return r;
        if(r==NULL) return l;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        int n=nodes.size();
        if(n==1){
            return nodes[0];
        }

        TreeNode* temp=lca(root,nodes[0],nodes[1]);

        for(int i=2;i<n;i++){
            temp=lca(root,temp,nodes[i]);
        }

        return temp;
    }
};