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
    void inorder(TreeNode* root,vector<int>&order){
        if(root==NULL) return;
        inorder(root->left,order);
        order.push_back(root->val);
        inorder(root->right,order);
    }
    bool check(TreeNode* root,long minval,long maxval){
        if(root==NULL) return true;
        if(root->val>minval && root->val<maxval){
            bool left=check(root->left,minval,root->val);
            bool right=check(root->right,root->val,maxval);
            return left&&right;
        }

        return false;
    }
    bool isValidBST(TreeNode* root) {
        long minval=LONG_MIN;
        long maxval=LONG_MAX;
        return check(root,minval,maxval);
    }
};

// logic is that the inorder of BST is always increasing
// time complexity: O(2*n) space complexity: O(n);


// we can use somrting min val, max Val concept for optimizing space complexity