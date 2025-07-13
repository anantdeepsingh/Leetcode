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
    ListNode* reverse(ListNode* head){
        if(head==NULL ||head->next==NULL) return head;

        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }

        return prev;
    }

    ListNode* find(ListNode* temp,int k){
        k--;
        while(temp!=NULL && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* swapPairs(ListNode* head) {
       ListNode* temp=head;
       ListNode* prev=NULL;
       while(temp!=NULL){
        ListNode* k=find(temp,2);
        if(k==NULL){
            if(prev){
                prev->next=temp;
            }
            break;
        }

        ListNode* next=k->next;
        k->next=NULL;
        ListNode* front=reverse(temp);
        if(temp==head){
            head=front;
        }
        else{
            prev->next=front;
        }

        prev=temp;
        temp=next;

       }

       return head;
    }
};