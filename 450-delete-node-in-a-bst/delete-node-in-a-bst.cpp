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
    void traverse(TreeNode* root,TreeNode* par,int key){
        // base case 
        if(root==NULL) return;
        if(root->val==key){
            TreeNode* left=root->left;
            TreeNode* right=root->right;
            if(right){
                TreeNode* temp=right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                if(par->left==root){
                    par->left=right;
                    temp->left=left;
                }
                else if(par->right==root){
                    par->right=right;
                    temp->left=left;
                }
            }
            else if(left){
                if(par!=root){
                    if(par->left==root){
                        par->left=left;
                    }
                    else{
                        par->right=left;
                    }
                }
            }
            else{
                if(par!=root){
                    if(par->left==root){
                        par->left=NULL;
                    }
                    else{
                        par->right=NULL;
                    }
                }
            }
            delete root;
            return;
        }
        if(root->val>key){
            traverse(root->left,root,key);
        }
        else{
            traverse(root->right,root,key);
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        TreeNode* dummy=new TreeNode(-1);
        dummy->left=root;
        traverse(root,dummy,key);
        return dummy->left;
    }
};