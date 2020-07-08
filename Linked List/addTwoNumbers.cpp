// Add Two Numbers - LeetCode
// Link - https://leetcode.com/problems/add-two-numbers/submissions/

// Question -
// You are given two non-empty linked lists representing two non-negative integers. The digits
// are stored in reverse order and each of their nodes contain a single digit. Add the two
// numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int val = 0;
        val = l1->val + l2->val;
        carry = val/10;
        ListNode * root = new ListNode(val%10);
        ListNode * node = root;
        l1 = l1->next;
        l2 = l2->next;
        
        while(l1 != NULL or l2 != NULL){
            int a, b;
            a = 0;
            b = 0;
            
            if(l1 != NULL){
                a = l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                b = l2->val;
                l2 = l2->next;
            }
            
            val = a + b + carry;
            node->next = new ListNode(val%10);
            carry = val/10;
            node = node->next;
        }
        
        while(carry){
            node->next = new ListNode(carry%10);
            node = node->next;
            carry = carry/10;
        }
        
        return root;
    }
};