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
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* nextNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp!=NULL){
            ListNode* kthNode=find(temp,k);
            if(kthNode==NULL){
               if(prevNode) prevNode->next=temp;
                break;
            }

            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;
            ListNode* front=reverse(temp);
            if(temp==head){
                head=front;
            }
            else{
                prevNode->next=front;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};
// time complexity : O(2*n)
//  space complexity: O(1)