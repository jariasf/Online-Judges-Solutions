/*******************************************
 ***Problema: Add Two Numbers II
 ***ID: Week1.7
 ***Juez: LeetCode
 ***Tipo: Linked Lists
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
    ListNode* reverseList(ListNode *l){
        ListNode* last = NULL, * tmp;
        while( l ){
            tmp = l -> next;
            l -> next = last;
            last = l;
            l = tmp;
        }
        return last;
    }    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1); l2 = reverseList(l2);
        ListNode *result = NULL, *head = NULL;
        int carry = 0, sum;
        while( l1 || l2 || carry ){
            sum = (l1 ?l1 -> val:0) + (l2? l2 -> val:0) + carry;
            if( sum > 9 ){
                carry = 1;
                sum %= 10;
            }else
                carry = 0;
            
            if( result == NULL )
                head = result = new ListNode(sum);
            else{
                result -> next = new ListNode( sum);
                result = result -> next;
            }  
            if( l1 ) l1 = l1 -> next;
            if( l2 ) l2 = l2 -> next;
        }
        
        return reverseList(head);
    }
};
