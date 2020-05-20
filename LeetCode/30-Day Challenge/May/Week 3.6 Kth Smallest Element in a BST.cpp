/*******************************************
 ***Problema: Kth Smallest Element in a BST
 ***ID: Week3.6
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    #define INF (1<<30)
    int kthSmallest(TreeNode* root, int &k) {
        if( root == NULL ) return -INF;
        int ans = kthSmallest( root -> left, k  );
        if( k == 0 ) return ans;
        k--;
        if( k == 0 ) return root -> val;
        ans = kthSmallest( root -> right , k  );
        return ans;
    }
};
