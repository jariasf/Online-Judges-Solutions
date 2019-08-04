/*******************************************
 ***Problema: Binary Tree Coloring Game
 ***ID: 1145
 ***Juez: LeetCode
 ***Tipo: Tree Traversal and Counting
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
    int count(TreeNode* root, int n, int x, int &maxi){
        if( root == NULL ) return 0;
        int left_cnt = count(root -> left, n, x, maxi);
        int right_cnt = count(root -> right, n, x, maxi);
        if( root -> val == x )
            maxi = max(maxi, max(left_cnt, max(right_cnt, n - left_cnt -right_cnt - 1)));
        return left_cnt + right_cnt + 1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int max = 0;
        count(root, n, x, max);
        return max > n - max;
    }
};
