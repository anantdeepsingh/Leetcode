class Solution {
public:
    int cameras = 0;

    // 0 = NOT_MONITORED, 1 = HAS_CAMERA, 2 = MONITORED
    int dfs(TreeNode* root) {
        if (!root) return 2; // null nodes are considered MONITORED

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == 0 || right == 0) {
            // If any child is NOT_MONITORED, put camera here
            cameras++;
            return 1;
        }

        if (left == 1 || right == 1) {
            // If any child has a camera, this node is monitored
            return 2;
        }

        // Otherwise, this node is not monitored
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) {
            // If root is not monitored, add a camera
            cameras++;
        }
        return cameras;
    }
};
