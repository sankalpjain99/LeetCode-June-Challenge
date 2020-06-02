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
        if(!node->next){
            node=NULL;
            return;
        }
        ListNode* temp = node->next;
        ListNode* curr = node;
        while(temp->next){
            curr->val = temp->val;
            curr=curr->next;
            temp=temp->next;
        }
        curr->val = temp->val;
        curr->next=NULL;
    }
};