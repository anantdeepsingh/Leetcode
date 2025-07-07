/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        map<Node*,Node*>mp;
        while(temp!=NULL){
            Node* dup=new Node(temp->val);
            mp[temp]=dup;
            temp=temp->next;
        }
        Node* dummy= new Node(1e6);
        mp[NULL]=NULL;
        temp=head;
        Node* res=dummy;
        while(temp!=NULL){
            Node* dup=mp[temp];
            cout<<temp<<endl;
            cout<<dup<<endl;
            dummy->next=dup;
            // cout<<dummy->next<<endl;
            dummy=dup;
            dummy->random=mp[temp->random];
            temp=temp->next;
        }

        return res->next;
    }
};