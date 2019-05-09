/*******************************************
 ***Problema: Maximum Binary Tree II
 ***ID: 998
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
    
    vector<int> inorder;
    void traversal(TreeNode *root){
        if( root == NULL ) return;
        traversal(root -> left);
        inorder.push_back(root -> val);
        traversal(root -> right);
    }
    
    TreeNode* createTree(int left, int right){
        if( left >= right ) return NULL;
        TreeNode* root;
        int maxi = inorder[left];
        int index = left;
        for( int i = left; i < right; ++i ){
            if( inorder[i] > maxi ){
                maxi = inorder[i];
                index = i;
            }
        }
        root = new TreeNode(maxi);
        root -> left = createTree(left, index);
        root -> right = createTree(index + 1, right);
        return root;
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        inorder.clear();
        traversal(root);
        inorder.push_back(val);
        return createTree(0, inorder.size());
    }
};
