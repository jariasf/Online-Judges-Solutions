/*******************************************
 ***Problema: Delete Node in a BST
 ***ID: Week5.3
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode* root ){
        return root -> left == NULL && root -> right == NULL;
    }
    
    TreeNode* getSuccessor(TreeNode* root){
        while( root -> left ){
            root = root -> left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if( root == NULL ) return NULL;
        if( root -> val == key ){
            if( isLeaf(root) ) return NULL;
            if( root -> left == NULL ) return root -> right;
            if( root -> right == NULL ) return root -> left;
            TreeNode* successor = getSuccessor(root -> right );
            root -> val = successor -> val;
            successor -> val = key;
            root -> right = deleteNode( root -> right, key);
        }else if( root -> val > key )
            root -> left = deleteNode( root -> left , key );
        else
            root -> right = deleteNode( root -> right, key );
        return root;
    }
};
