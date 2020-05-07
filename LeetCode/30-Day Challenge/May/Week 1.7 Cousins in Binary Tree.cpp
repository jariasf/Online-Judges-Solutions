/*******************************************
 ***Problema: Cousins in Binary Tree
 ***ID: Week1.7
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
    
    int x_parent, y_parent, x_depth, y_depth;
    void traverse(TreeNode* root, int parent, int x, int y, int depth){
        if( root == NULL || (x_parent != -1 && y_parent != -1) ) return;
        if( root -> val == x ){
            x_parent = parent;
            x_depth = depth;
        }
        if( root -> val == y ){
            y_parent = parent;
            y_depth = depth;
        }
        
        traverse(root -> left, root -> val , x, y, depth + 1);
        traverse(root -> right, root -> val, x, y, depth + 1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        x_parent = y_parent = -1;
        traverse(root, -1, x, y, 0);
        return x_parent != y_parent && x_depth == y_depth;
    }
};
