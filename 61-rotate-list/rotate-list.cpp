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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || head->next==NULL) return head;
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }

        int n=k%len;
        if(n==0) return head;

        temp=head;
        ListNode* front=reverse(temp);

        temp=front;
        ListNode* nthNode=find(temp,n);
        cout<<nthNode->val<<endl;
        ListNode* nextNode=nthNode->next;
        nthNode->next=NULL;
        reverse(temp);
        ListNode* last=reverse(nextNode);
        front=nthNode;
        temp->next=last;

        return front;
        
    }
};