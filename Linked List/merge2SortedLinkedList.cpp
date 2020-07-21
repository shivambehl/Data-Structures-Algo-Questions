// Merge Two sorted LinkedList

// Link - https://leetcode.com/problems/merge-two-sorted-lists/submissions/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                dummy->next = l1;
                l1 = l1->next;
            }
            else{
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy= dummy->next;
        }
        
        if(l1!=NULL){
            dummy->next = l1;
            //l1 = l1->next;
        }
        else if(l2!=NULL){
            dummy->next = l2;
            //l2 = l2->next;
        }
        
        return head->next;
    }
};