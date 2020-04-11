/*******************************************
 ***Problema: Diameter of Binary Tree
 ***ID: Week2.4
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int longestPath(TreeNode* root, int &diameter){        
        if( root == NULL) return 0;
        int nodes_left = longestPath(root -> left, diameter);
        int nodes_right = longestPath(root -> right, diameter);
        diameter = max(diameter, nodes_left + nodes_right );
        return 1 + max(nodes_left, nodes_right); 
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        longestPath(root, diameter);
        return diameter;
    }
};
