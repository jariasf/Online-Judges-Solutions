/*******************************************
 ***Problema: Invert Binary Tree
 ***ID: Week1.1
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if( root == NULL ) return root;
        TreeNode* pLeft = root -> left, *pRight = root -> right;
        root -> left = invertTree(pRight);
        root -> right = invertTree(pLeft);
        return root;
    }
};
