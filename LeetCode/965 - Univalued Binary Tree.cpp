/*******************************************
 ***Problema: Univalued Binary Tree
 ***ID: 965
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
    
    bool possible(TreeNode* root, int val){
        if( root == NULL ) return true;
        if( root -> val != val ) return false;
        return possible(root -> left, val) & possible(root -> right, val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        if( root == NULL ) return true;
        int val = root -> val;
        return possible(root, val);
    }
};
