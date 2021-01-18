/*******************************************
 ***Problema: Add Two Numbers
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: LinkedList
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

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
        ListNode *sum = NULL;
        ListNode *res = NULL;
        bool first = true;
        while( l1 || l2 ){
            int s = 0;
            if( l1 ){
                s = l1 -> val;
                l1 = l1 -> next;
            }
            if( l2 ){
                s += l2 -> val;
                l2 = l2 -> next;
            }
            
            s += carry;
            if( s >= 10 ){
                carry = 1;
                s = s - 10;
            }else{
                carry = 0;
            }
            if( sum == NULL ){
                sum = new ListNode(s);
                res = sum;
            }else{
                sum -> next = new ListNode(s);
                sum = sum -> next;
            }
        }
        if( carry )
            sum -> next = new ListNode(1);
        
        return res;
    }
};
