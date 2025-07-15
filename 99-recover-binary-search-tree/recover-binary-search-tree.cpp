class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;

    void traverse(TreeNode* root) {
        if (root == NULL) return;

        traverse(root->left);

        if(prev && root->val<prev->val){
            if(!first){
                first=prev;
                middle=root;
            }
            last=root;
        }
        prev=root;
        traverse(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = prev = NULL;
        traverse(root);

        if (last) {
            swap(first->val, last->val);
        } else {
            swap(first->val, middle->val);
        }
    }
};
