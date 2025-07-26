/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// each of them is provided with their val of itself and vector of address of thier neighbours
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        map<Node*,Node*>mp;
        mp[node]=new Node(node->val);
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            for(auto it:node->neighbors){
                if(!mp[it]){
                    mp[it]=new Node(it->val);
                    q.push(it);
                }

                mp[node]->neighbors.push_back(mp[it]);
            }
        }

        return mp[node];
    }
};

