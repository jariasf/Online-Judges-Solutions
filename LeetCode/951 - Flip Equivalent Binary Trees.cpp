/*******************************************
 ***Problema: Flip Equivalent Binary Trees
 ***ID: 951
 ***Juez: LeetCode
 ***Tipo: Binary Tree
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if( root1 == NULL && root2 != NULL ) return false;
        if( root2 == NULL && root1 != NULL ) return false;
        if( root1 == NULL && root2 == NULL ) return true;
        if( root1 -> val != root2 -> val ) return false;
        TreeNode* L1 = root1 -> left, *R1 = root1 -> right;
        TreeNode* L2 = root2 -> left, *R2 = root2 -> right;
        bool left = flipEquiv(L1, L2) & flipEquiv(R1, R2);
        bool right = flipEquiv(L1, R2) & flipEquiv(R1, L2);
        return left | right;
    }
};
