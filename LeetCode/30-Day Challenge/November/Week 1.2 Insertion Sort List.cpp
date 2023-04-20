/*******************************************
 ***Problema: Insertion Sort List
 ***ID: Week1.2
 ***Juez: LeetCode
 ***Tipo: Linked List + Bitwise operations
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *current = head;
        ListNode *last = NULL;    
        while( current ){
            ListNode *tmp = current;
            ListNode *next = current -> next;
            tmp -> next = last;
            while( last && tmp -> val < last -> val ){
                swap( last -> val, tmp -> val );
                last = last -> next;
                tmp = tmp -> next;
            }
            last = current;
            current = next;
        }
        
        current = last;
        last = NULL;
        while( current ){
            ListNode *tmp = current -> next;
            current -> next = last;
            last = current;
            current = tmp;
        }
        
        return last;
    }
};
