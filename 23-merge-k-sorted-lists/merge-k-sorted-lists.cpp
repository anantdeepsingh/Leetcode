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
     ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return  list1;
        }

        ListNode* head=(list1->val<=list2->val)?list1:list2;
        ListNode* prev=NULL;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                if(prev) prev->next=temp1;
                prev=temp1;
                temp1=temp1->next;
            }
            else{
                if(prev)prev->next=temp2;
                prev=temp2;
                temp2=temp2->next;
            }
        }
        cout<<temp1<<" "<<temp2<<endl;
        if(temp1!=NULL){
            prev->next=temp1;
        }
        if(temp2!=NULL){
            prev->next=temp2;
        }

        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(size==0) return NULL;
        if(size==1) return lists[0];
        ListNode* ans=merge(lists[0],lists[1]);
        for(int i=2;i<size;i++){
            ans=merge(ans,lists[i]);
        }
        return ans;
    }
};