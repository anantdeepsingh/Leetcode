/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "null";
        queue<TreeNode*>q;
        string res="";
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp){
                res+=to_string(temp->val)+",";
                q.push(temp->left);
                q.push(temp->right);
            }
            else{
                res+="null,";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="null") return NULL;
        stringstream ss(data);
        string token;
        getline(ss,token,',');
        TreeNode* root=new TreeNode(stoi(token));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(!getline(ss,token,',')) break;
            if(token!="null"){
                temp->left=new TreeNode(stoi(token));
                q.push(temp->left);
            }
            if(!getline(ss,token,',')) break;
            if(token!="null"){
                temp->right=new TreeNode(stoi(token));
                q.push(temp->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));