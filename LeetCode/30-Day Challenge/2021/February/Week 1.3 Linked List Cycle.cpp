/*******************************************
 ***Problema: Linked List Cycle
 ***ID: Week1.3
 ***Juez: LeetCode
 ***Tipo: Fast and Slow pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

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
    bool hasCycle(ListNode *head) {
        if( head == NULL || head -> next == NULL ) 
            return false;
        
        ListNode* hare, *tortoise;
        hare = tortoise = head;
        
        hare = hare -> next -> next;
        tortoise = tortoise -> next;
        
        while( hare && hare -> next ){
            if( hare -> val == tortoise -> val ){
                return true;
            }
            hare = hare -> next -> next;
            tortoise = tortoise -> next;
        }
        return false;
    }
};
