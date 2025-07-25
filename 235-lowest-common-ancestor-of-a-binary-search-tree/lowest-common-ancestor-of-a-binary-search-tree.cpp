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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int val=root->val;
        int v1=p->val;
        int v2=q->val;
        if(v1<val && v2<val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(v1>val && v2>val){
            return lowestCommonAncestor(root->right,p,q);
        }

        return root;
    }
};