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
    bool isValidBST(TreeNode* root) {
        vector<int>order;
        inorder(root,order);
        for(int i=1;i<order.size();i++){
            if(order[i]<=order[i-1]) return false;
        }
        return  true;
    }
};

// logic is that the inorder of BST is always increasing
// time complexity: O(2*n) space complexity: O(n);