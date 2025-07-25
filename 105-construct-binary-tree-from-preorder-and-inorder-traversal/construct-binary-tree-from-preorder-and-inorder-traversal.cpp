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
    TreeNode* build(int start,int end,int ind,vector<int>&preorder,vector<int>& inorder){
        if(start>end) return NULL;

        TreeNode* root=new TreeNode(preorder[ind]);
        int j;
        for(int i=start;i<=end;i++){
            if(inorder[i]==preorder[ind]){
                j=i;
                break;
            }
        }
        int len=j-start+1;
        root->left=build(start,j-1,ind+1,preorder,inorder);
        root->right=build(j+1,end,ind+len,preorder,inorder);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return build(0,n-1,0,preorder,inorder);
    }
};