/*******************************************
 ***Problema: Increasing Order Search Tree
 ***ID: Week1.3
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
    
    void traverse(TreeNode* root, vector<int> &current){
        if( root == NULL ) return;
        traverse(root -> left, current);
        current.push_back(root -> val);
        traverse(root -> right, current);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if( root == NULL ) return NULL;
        vector<int> current;
        traverse(root, current);
        TreeNode* aux = new TreeNode(current[0]);
        TreeNode* newRoot = aux;
        for( int i = 1 ; i < current.size(); ++i ){
            aux -> right = new TreeNode(current[i]);
            aux = aux -> right;
        }
        return newRoot;
    }
};
