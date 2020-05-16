/*******************************************
 ***Problema: Odd Even Linked List
 ***ID: Week3.2
 ***Juez: LeetCode
 ***Tipo: Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if( head == NULL ) return head;
        ListNode* odd = head;
        ListNode* even_start = head -> next;
        ListNode* even = head -> next; 
        while( even && even -> next ){
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = odd -> next;
            even = even -> next;
        }
        odd -> next = even_start;
        return head;
    }
};
