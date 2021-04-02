/*******************************************
 ***Problema: Intersection of Two Linked Lists
 ***ID: 160
 ***Juez: LintCode
 ***Tipo: Linked List Length
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
    
    int getLength(ListNode *head){
        int length = 0;
        while(head){
            length++;
            head = head -> next;
        }
        return length;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA), lenB = getLength(headB);
        ListNode *A = headA, *B = headB;
        while(lenA > lenB){
            A = A -> next;
            lenA--;
        }

        while( lenB > lenA ){
            B = B -> next;
            lenB--;
        }

        while( A && B && A != B ){
            A = A -> next;
            B = B -> next;
        }
        return A;
    }
};
