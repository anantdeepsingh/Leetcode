/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* head;
        if(list1->val<=list2->val){
            head=list1;
        }
        else{
            head=list2;
        }

        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* prev=NULL;
        while(temp1!=NULL and temp2!=NULL){
            if(temp1->val<=temp2->val){
                if(prev) prev->next=temp1;
                prev=temp1;
                temp1=temp1->next;
            }
            else{
                if(prev) prev->next=temp2;
                prev=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1!=NULL){
            prev->next=temp1;
        }
        if(temp2!=NULL){
            prev->next=temp2;
        }

        return head;
    }

};