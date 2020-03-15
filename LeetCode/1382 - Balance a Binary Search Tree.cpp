/*******************************************
 ***Problem: Balance a Binary Search Tree
 ***ID: 1382
 ***Judge: LeetCode
 ***Type: BST - Inorder Traversal
 ***Author: Jhosimar George Arias Figueroa
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
    vector<TreeNode*> inorder;
    
    void traverse(TreeNode* root){
        if( root == NULL ) return;
        traverse(root -> left);
        inorder.push_back(root);
        traverse(root -> right);
    }
    
    TreeNode* builtTree(int left, int right){
        if( left > right ) return NULL;
        int mid = (left + right)/2;
        TreeNode* root = inorder[mid];
        root -> left = builtTree(left, mid - 1);
        root -> right = builtTree(mid + 1, right);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder.clear();
        traverse(root);
        return builtTree(0, inorder.size() - 1);
    }
};
