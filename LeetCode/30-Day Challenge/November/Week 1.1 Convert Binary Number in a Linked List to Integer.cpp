/*******************************************
 ***Problema: Convert Binary Number in a Linked List to Integer
 ***ID: Week1.1
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
    int getDecimalValue(ListNode* head) {
        int val = 0;
        while(head){
            val = (val<<1);
            if( head -> val == 1 ){
                val |= 1;
            }
            head = head -> next;
        }
        return val;
    }
};
