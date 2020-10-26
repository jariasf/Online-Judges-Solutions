/*******************************************
 ***Problema: Rotate List
 ***ID: Week1.7
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

    int getLength(ListNode* head){
        int size = 0;
        while( head ){
            head = head -> next;
            size++;
        }
        return size;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if( head == NULL || head -> next == NULL ) return head;
        
        int n = getLength(head);
        k = (k - 1) % n + 1;
        if( k == n ) return head;
        
        ListNode* current = head;
        int last_index = n - k - 1;
        while( last_index-- > 0 )
            current = current -> next;
        
        ListNode* tmp = current -> next;
        current -> next = NULL;
        
        if( tmp ){
            current = tmp;
            while( tmp -> next ){
                tmp = tmp -> next;
            }
            tmp -> next = head;
            head = current;
        }
        return head;
    }
};
