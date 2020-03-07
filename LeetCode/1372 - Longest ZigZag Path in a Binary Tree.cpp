/*******************************************
 ***Problem: Longest ZigZag Path in a Binary Tree
 ***ID: 1372
 ***Judge: LeetCode
 ***Type: Binary Tree traversal
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
    #define NONE -1
    #define LEFT 1
    #define RIGHT 2
    
    int res;
    void solve(TreeNode* root, int last, int sum){
        res = max(res, sum);
        if( root == NULL )
            return;
        
        int aux = sum;
        if( last != LEFT )
            aux++;
        else
            aux = 1;
        solve(root -> left, LEFT, aux);
        aux = sum;
        if( last != RIGHT )
            aux++;
        else
            aux = 1;
                
        solve(root -> right, RIGHT, aux);
    }    

    int longestZigZag(TreeNode* root) {
        res = 0;
        solve(root, NONE, 0);
        return res - 1;
    }
};
