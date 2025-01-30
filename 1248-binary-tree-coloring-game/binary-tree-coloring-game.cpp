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
    int countChild(TreeNode* node) {
        int cnt = 0;
        queue<TreeNode*> q1;
        q1.push(node);
        while (!q1.empty()) {
            TreeNode* curr = q1.front();  // Fixed variable shadowing issue
            q1.pop();
            cnt++;

            if (curr->left) {
                q1.push(curr->left);
            }
            if (curr->right) {
                q1.push(curr->right);
            }
        }
        return cnt;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int cnt1 = 0, cnt2 = 0;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        TreeNode* node = nullptr;
        TreeNode* parent = nullptr;
        
        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            TreeNode* par = q.front().second;
            q.pop();

            if (curr->val == x) {
                node = curr;
                parent = par;
                break;
            }

            if (curr->left) {
                q.push({curr->left, curr});
            }
            if (curr->right) {
                q.push({curr->right, curr});
            }
        }

        if (node->left) cnt1 = countChild(node->left);
        if (node->right) cnt2 = countChild(node->right);
        
        int parentSize = n - (cnt1 + cnt2 + 1);

        return (cnt1 > n / 2) || (cnt2 > n / 2) || (parentSize > n / 2);
    }
};
