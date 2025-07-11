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
    bool f1,f2;
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return root;
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        if(root->val==p->val){
            f1=true;
            return root;
        }

        if(root->val==q->val){
            f2=true;
            return root;
        }

        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        f1=false;
        f2=false;
        TreeNode* temp=lca(root,p,q);
        if(f1 && f2) return temp;
        return NULL;
    }
};