/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node;
        ListNode* prev;
        while(temp->next!=NULL){
            ListNode* nxt=temp->next;
            int data=nxt->val;
            temp->val=data;
            prev=temp;
            temp=nxt;
        }
        prev->next=NULL;
        delete temp;
        
    }
};