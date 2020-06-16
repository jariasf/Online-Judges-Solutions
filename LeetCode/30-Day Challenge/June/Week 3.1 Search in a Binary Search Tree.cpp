/*******************************************
 ***Problema: Search in a Binary Search Tree
 ***ID: Week3.1
 ***Juez: LeetCode
 ***Tipo: Recursion - BST
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if( root == NULL ) return NULL;
        if( root -> val == val ) return root;
        if( root -> val > val )
            return searchBST(root -> left, val);
        return searchBST(root -> right, val);
    }
};
