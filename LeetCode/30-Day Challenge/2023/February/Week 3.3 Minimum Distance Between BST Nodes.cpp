/*******************************************
 ***Problema: Minimum Distance Between BST Nodes
 ***ID: Week 3.3
 ***Juez: LeetCode
 ***Tipo: Inorder traversal
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
    void inorder(TreeNode* root, TreeNode*& prev, int &min_difference){
        if( root == nullptr ) return;
        inorder(root -> left, prev, min_difference);
        if(prev != nullptr)
            min_difference = min( root -> val - prev -> val, min_difference);
        prev = root;
        inorder(root -> right, prev, min_difference);
    }

    int minDiffInBST(TreeNode* root) {
        int min_difference = INT_MAX;        
        TreeNode* prev = nullptr;
        inorder(root, prev, min_difference);
        return min_difference;
    }
};
