/*******************************************
 ***Problema: Sort List
 ***ID: Week2.6
 ***Juez: LeetCode
 ***Tipo: Sorting + Linked List
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
    ListNode* middle(ListNode* start){
        ListNode* runner = start -> next;
        while( runner && runner -> next ){
            start = start -> next;
            runner = runner -> next -> next;
        }
        return start;
    }
    
    ListNode* merge( ListNode* left, ListNode* right ){
        
        if( left == NULL ) return right;
        if( right == NULL ) return left;
        
        ListNode* head = right, *current;
        if( left -> val < right -> val )
            head = left, left = left -> next;
        else
            right = right -> next;
            
        current = head;
        while( left && right ){
            if( left -> val < right -> val ){
                current -> next = left;
                left = left -> next;
            }else{
                current -> next = right;
                right = right -> next;
            }
            current = current -> next;
        }
        
        if( left ) current -> next = left;
        else if( right ) current -> next = right;
        
        return head;
    }

    ListNode* sortList(ListNode* head){
        if( head == NULL || head -> next == NULL ) return head;
        ListNode* mid = middle(head);
        ListNode *tmp = mid -> next;
        mid -> next = NULL;
        ListNode* l = sortList(head);
        ListNode* r = sortList(tmp);
        return merge( l, r );
    }
};
