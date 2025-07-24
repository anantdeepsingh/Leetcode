/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x) : left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, TreeNode* par, int key) {
        if (root == NULL) return;

        if (root->val == key) {
            // Node found
            if (root->right) {
                // Find in-order successor
                TreeNode* succ = root->right;
                TreeNode* succPar = root;

                while (succ->left) {
                    succPar = succ;
                    succ = succ->left;
                }

                // If successor is not root->right directly
                if (succPar != root) {
                    succPar->left = succ->right; // remove successor from its place
                    succ->right = root->right;
                }
                succ->left = root->left;

                if (par->left == root) {
                    par->left = succ;
                } else if (par->right == root) {
                    par->right = succ;
                }

                delete root;
            } else if (root->left) {
                // No right child, but left child
                if (par->left == root) {
                    par->left = root->left;
                } else if (par->right == root) {
                    par->right = root->left;
                }
                delete root;
            } else {
                // Leaf node
                if (par->left == root) {
                    par->left = nullptr;
                } else if (par->right == root) {
                    par->right = nullptr;
                }
                delete root;
            }
            return;
        }

        if (key < root->val) {
            traverse(root->left, root, key);
        } else {
            traverse(root->right, root, key);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // Special case: if the root itself needs to be deleted
        TreeNode dummy(0);
        dummy.left = root;

        traverse(root, &dummy, key);

        return dummy.left;
    }
};
