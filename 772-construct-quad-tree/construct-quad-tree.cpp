/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    pair<bool,bool> check(int r1,int c1,int r2,int c2,vector<vector<int>>& grid){
        int cnt1=0,cnt0=0;
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                if(grid[i][j]==1){
                    cnt1++;
                }
                else cnt0++;
            }
        }

        if(cnt0!=0 && cnt1!=0) return {0,1};
        if(cnt1==0) return {1,0};

        return {1,1};
    }
    Node* f(int r1,int c1,int r2,int c2,vector<vector<int>>& grid){
        if(r1==r2 && c1==c2){
            Node* temp=new Node(grid[r1][c1],1);
            return temp;
        }
        Node* root=new Node();
        // Node* topLeft=NULL;
        // Node* topRight=NULL;
        // Node* bottomLeft=NULL;
        // Node* bottomRight=NULL;
        // isleaf,val
        pair<bool,bool>p=check(r1,c1,r2,c2,grid);
        root->isLeaf=p.first;
        root->val=p.second;
        if(!root->isLeaf){
            int gap=(r2-r1+1)/2;
            root->topLeft=f(r1,c1,r1+gap-1,c1+gap-1,grid);
            root->topRight=f(r1,c1+gap,r1+gap-1,c2,grid);
            root->bottomLeft=f(r1+gap,c1,r2,c1+gap-1,grid);
            root->bottomRight=f(r1+gap,c1+gap,r2,c2,grid);
        }
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return f(0,0,n-1,n-1,grid);
    }
};