/*******************************************
 ***Problema: Same Tree
 ***ID: Week2.6
 ***Juez: LeetCode
 ***Tipo: Tree Traversal
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( (!p && q) || (p && !q) ) return false;
        if( !p && !q ) return true;
        if( p -> val != q -> val ) return false;
        return isSameTree(p -> left, q -> left) && isSameTree(p -> right , q -> right);
    }
};
