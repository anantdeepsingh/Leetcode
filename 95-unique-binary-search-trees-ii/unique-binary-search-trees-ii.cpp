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
    // vector<TreeNode*>ans;
    vector<TreeNode*> generateAll(int start,int end){
        vector<TreeNode*>res;
        if(start>end){
            return {NULL};
        }

        if(start==end){
            TreeNode* node=new TreeNode(start);
            return {node};
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*>left=generateAll(start,i-1);
            vector<TreeNode*>right=generateAll(i+1,end);

            for(auto &l:left){
                for(auto &r:right){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }

        return res;

    }
    vector<TreeNode*> generateTrees(int n) {
       return generateAll(1,n);
    }
};