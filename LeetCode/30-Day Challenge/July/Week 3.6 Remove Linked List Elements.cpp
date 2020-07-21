/*******************************************
 ***Problema: Remove Linked List Elements
 ***ID: Week3.6
 ***Juez: LeetCode
 ***Tipo: Linked List traversal
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* last = dummy, *cur = head;
        while(cur){
            if( cur -> val == val ){
                cur = cur -> next;
                last -> next = cur;                
            }else{
                last = last -> next;
                if( cur ) cur = cur -> next;
            }
        }
        return dummy -> next;
    }
};
