/*******************************************
 ***Problema: Range Sum of BST
 ***ID: 938
 ***Juez: LeetCode
 ***Tipo: Binary Tree Traversal
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
    
    void inorder(TreeNode* root, int &res, int L, int R){
        if( root == NULL ) return;
        inorder(root -> left, res, L, R);
        if( root -> val >= L && root -> val <= R ) res += root -> val;
        inorder(root -> right, res, L, R);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        inorder(root, res, L, R);
        return res;
    }
};
