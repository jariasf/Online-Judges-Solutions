/*******************************************
 ***Problema: Count Good Nodes in Binary Tree
 ***ID: 1448
 ***Juez: LeetCode
 ***Tipo: DFS
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
    int cnt;
    void traverse(TreeNode* root, int maxi){
        if( root == NULL ) return;
        if( root -> val >= maxi ) cnt++;
        traverse(root -> left, max(maxi, root ->val) );
        traverse(root -> right, max(maxi, root ->val) );        
    }
    
    int goodNodes(TreeNode* root) {
        cnt = 0;
        traverse(root, INT_MIN);
        return cnt;
    }
};
