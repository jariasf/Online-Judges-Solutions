/*******************************************
 ***Problema: Validate Binary Search Tree
 ***ID: Week3.2
 ***Juez: LeetCode
 ***Tipo: Recursion
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValid(TreeNode* A, long long min , long long max ){ 
        if( A == NULL ) return 1;
        if( A -> val > min && A -> val < max && isValid(A -> left, min, A -> val ) && isValid(A -> right, A -> val , max ) )
            return 1;
        return 0;
    }
    
    bool isValidBST(TreeNode* A){
        return isValid(A, -(1LL<<60), 1LL<<60 );
    }
};
