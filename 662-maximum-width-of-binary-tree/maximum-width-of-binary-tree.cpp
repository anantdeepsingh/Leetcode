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
 #define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    unsigned long long maxWidth = 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 1});

    while (!q.empty()) {
        int size = q.size();
        unsigned long long first = q.front().second, last = 0;

        for (int i = 0; i < size; ++i) {
            auto [node, idx] = q.front(); q.pop();
            last = idx;

            if (node->left) q.push({node->left, idx * 2});
            if (node->right) q.push({node->right, idx * 2 + 1});
        }

        maxWidth = max(maxWidth, last - first + 1);
    }

    return maxWidth;
}

};