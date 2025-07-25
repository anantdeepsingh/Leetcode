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
    TreeNode* build(int start,int end,int ind,vector<int>&inorder,vector<int>&postorder){
        int n=inorder.size();
        if(start>end) return NULL;
        int j;
        for(int i=start;i<=end;i++){
            if(postorder[ind]==inorder[i]){
                j=i;
                break;
            }
        }
        TreeNode* root=new TreeNode(postorder[ind]);
        int len=end-j;
        root->left=build(start,j-1,ind-len-1,inorder,postorder);
        root->right=build(j+1,end,ind-1,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return build(0,n-1,n-1,inorder,postorder);
    }
};