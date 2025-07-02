/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* order(Node* head){
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL){
            if(temp->child!=NULL){
               Node* beta=temp->child;
               Node* last=order(temp->child);
               Node* nextNode=temp->next;
               temp->next=beta;
               beta->prev=temp;
               if(nextNode!=NULL){
                last->next=nextNode;
                nextNode->prev=last;
               }
               temp->child=NULL;
               prev=last;
               temp=nextNode;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return prev;
    }
    Node* flatten(Node* head) {
        order(head);
        return head;
    }
};