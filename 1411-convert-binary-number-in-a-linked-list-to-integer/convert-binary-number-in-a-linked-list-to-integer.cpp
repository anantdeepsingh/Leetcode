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
    int getDecimalValue(ListNode* head) {
        vector<int>values;
        ListNode* temp=head;
        while(temp!=NULL){
            values.push_back(temp->val);
            temp=temp->next;
        }

        reverse(values.begin(),values.end());
        int number=0;
        for(int i=0;i<values.size();i++){
            if(values[i]){
                number|=(1<<i);
            }
        }
        return number;
    }
};