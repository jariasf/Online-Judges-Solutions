/*******************************************
 ***Problema: Merge Two Sorted Lists
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Linked List Manipulation
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* last = new ListNode(-1), *head = last;
        
        while( l1 || l2 ){
            if( l1 && l2 ){
                if( l1 -> val < l2 -> val ){
                    last -> next = l1;
                    l1 = l1 -> next;
                }else{
                    last -> next = l2;
                    l2 = l2 -> next;
                }
                last = last -> next;
            }else if( l1 ){
                last -> next = l1;
                break;
            }else if( l2 ){
                last -> next = l2;
                break;
            }
        }
        
        return head -> next;
    }
};
