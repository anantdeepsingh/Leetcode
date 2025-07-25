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
        int lsum=max(0,Sum(root->left));
        int rsum=max(0,Sum(root->right));

        // cout<<lsum<<" "<<rsum<<endl;
        mx=max({mx,lsum+rsum+root->val});
        return max(lsum,rsum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        Sum(root);
        return mx;
    }
};