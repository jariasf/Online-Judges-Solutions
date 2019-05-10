/*******************************************
 ***Problema: Cousins in Binary Tree
 ***ID: 993
 ***Juez: LeetCode
 ***Tipo: Binary Trees
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
    
    bool solve(TreeNode *root, TreeNode *parent, int x, int y){
        if( root == NULL ) return false;
        if( root -> val == x ){
            if( parent && parent -> left != NULL && parent -> left -> val == y ) return false;
            if( parent && parent -> right != NULL && parent -> right -> val == y ) return false;
            return true;
        }else if(root -> val == y ){
            if( parent && parent -> left != NULL && parent -> left -> val == x ) return false;
            if( parent && parent -> right != NULL && parent -> right -> val == x ) return false;            
            return true;
        }
        return solve( root -> left, root, x, y) | solve( root -> right, root, x, y);
    }
    
    int getDepth(TreeNode* root, int x, int d ){
        if( root == NULL ) return -1;
        if( root -> val == x ) return d;
        return max(getDepth(root -> left, x, d + 1), getDepth(root -> right, x, d + 1));
    }
    
    bool sameDepth(TreeNode * root , int x , int y){
        return getDepth(root, x, 0) == getDepth(root, y, 0);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if( sameDepth(root, x, y))
            return solve(root, NULL, x, y);
        return false;
    }
};
