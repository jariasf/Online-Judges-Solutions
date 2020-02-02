/*******************************************
 ***Problema: Maximum Product of Splitted Binary Tree
 ***ID: 1343
 ***Juez: LeetCode
 ***Tipo: Binary Tree Traversal
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
// Changing node values
class Solution {
public:
    typedef long long LL;
    int MOD = 1e9 + 7;
    int calSum(TreeNode* root){
        if( root == NULL )
            return 0;
        int sum = root -> val + calSum(root -> left) + calSum(root -> right);
        root -> val = sum;
        return sum;
    }
    
    LL solve(TreeNode* root, LL tot){
        if( root == NULL )
            return 0;    
        LL sum = root -> val;
        LL maximum = (tot - sum) * sum;
        return max( maximum, max(solve(root -> left, tot), solve(root -> right, tot)));
    }
    
    int maxProduct(TreeNode* root) {
        int tot = calSum(root);
        return solve(root, tot) % MOD;
    }
};

// Without changing node values
class Solution {
public:
    typedef long long LL;
    int MOD = 1e9 + 7;
    LL maximum;
    int calSum(TreeNode* root){
        if( root == NULL )
            return 0;
        return root -> val + calSum(root -> left) + calSum(root -> right);
    }
    
    LL solve(TreeNode* root, LL tot){
        if( root == NULL )
            return 0;    
        LL sum = root -> val + solve(root -> left, tot) + solve(root -> right, tot);
        maximum = max( maximum, (tot - sum) * sum);
        return sum;
    }
    
    int maxProduct(TreeNode* root) {
        int tot = calSum(root);
        maximum = 0;
        solve(root, tot);
        return maximum % MOD;
    }
};
