class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;

        queue<Node*> q;
        unordered_map<Node*, Node*> mp;
        mp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            vector<Node*> adj; 

            for (auto it : temp->neighbors) {
                if (!mp[it]) {
                    mp[it] = new Node(it->val);  // clone neighbor
                    q.push(it);
                }
                adj.push_back(mp[it]);  // push clone neighbor
            }

            mp[temp]->neighbors = adj;  // set clone's neighbors
        }

        return mp[node];  // return clone of original start
    }
};
