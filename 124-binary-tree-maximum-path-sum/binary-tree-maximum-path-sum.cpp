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
    int mx=INT_MIN;
    int Sum(TreeNode* root){
        if(root==NULL) return 0;
        int lsum=Sum(root->left);
        int rsum=Sum(root->right);

        int op1=lsum+rsum+root->val;
        int op2=max(lsum,rsum)+root->val;
        int op3=root->val;
        mx=max({mx,op1,op2,op3});
        return max(op2,op3);
    }
    int maxPathSum(TreeNode* root) {
        Sum(root);
        return mx;
    }
};