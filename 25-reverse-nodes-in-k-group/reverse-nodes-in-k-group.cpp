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
    ListNode* rev(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* find(ListNode* head,int k){
        ListNode* temp=head;
        ListNode* prev=NULL;
        k--;
        while(temp!=NULL && k>0){
            prev=temp;
            temp=temp->next;
            k--;
        }

        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* kthNode=find(temp,k);
            if(kthNode){
                cout<<kthNode->val<<endl;
            }
            if(kthNode==NULL){
                if(prev) prev->next=temp;
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;
            ListNode* newHead=rev(temp);

            if(temp==head){
                head=newHead ;   
            }
            else{
                prev->next=newHead;
            }
            prev=temp;
            temp=nextNode;
        }

        return head;
    }
};