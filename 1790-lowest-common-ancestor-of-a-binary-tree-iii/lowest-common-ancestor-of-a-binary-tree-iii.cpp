/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*>v1,v2;
        Node* temp=p;
        map<Node*,int>mp;
        while(temp!=NULL){
            v1.push_back(temp);
            mp[temp]++;
            temp=temp->parent;
        }
        temp=q;
        while(temp!=NULL){
            v2.push_back(temp);
            if(mp.count(temp)) return temp;
            temp=temp->parent;
        }


        return NULL;
    }
};