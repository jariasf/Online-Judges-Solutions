/*******************************************
 ***Problema: Reorder List
 ***ID: Week3.6
 ***Juez: LeetCode
 ***Tipo: Linked List
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//3 steps: 
//1. Get middle node
//2. Reverse pointers from middle to end
//3. Reorder pointers using first and last nodes
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
    
    ListNode* getMiddle(ListNode *head){
        ListNode* slow = head, *fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode* reorderPointers(ListNode* head){       
        ListNode* last = getMiddle(head);
        ListNode* cur = last -> next;
        last -> next = NULL;        
        while(cur){
            ListNode* tmp = cur -> next;
            cur -> next = last;
            last = cur;
            cur = tmp;
        }
        return last;
    }
    
    void reorderList(ListNode* head) {  
        if( head == NULL ) return;
        ListNode* tail = reorderPointers(head);
        ListNode* cur = head;
        
        while(cur){
            ListNode *tmp_cur = cur -> next;
            cur -> next = tail;
            ListNode* tmp_last = tail -> next;
            tail -> next = tmp_cur;
            tail = tmp_last;
            cur = tmp_cur;
        } 
    }
};
