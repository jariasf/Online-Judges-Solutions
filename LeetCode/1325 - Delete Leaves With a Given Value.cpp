/*******************************************
 ***Problema: Delete Leaves With a Given Value
 ***ID: 1325
 ***Juez: LeetCode
 ***Tipo: Binary Tree Postorder traversal
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
    bool isLeaf(TreeNode* root){
        return root -> left == NULL && root -> right == NULL;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if( root == NULL) return NULL;
        root -> left = removeLeafNodes(root -> left, target);
        root -> right = removeLeafNodes(root -> right, target);
        if( root -> val == target && isLeaf(root) ){
            return NULL;
        }
        return root;
    }
};
