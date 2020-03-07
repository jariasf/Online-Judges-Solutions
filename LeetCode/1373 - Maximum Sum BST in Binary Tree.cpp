/*******************************************
 ***Problem: Maximum Sum BST in Binary Tree
 ***ID: 1373
 ***Judge: LeetCode
 ***Type: BST + DP
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
    
    struct State{
        int min_val, max_val, sum, max_sum;
        State(int _min_val, int _max_val, int _sum, int _max_sum){
            min_val = _min_val;
            max_val = _max_val;
            sum = _sum;
            max_sum = _max_sum;
        }
    };

    State solve(TreeNode* root){
        if( root == NULL ){
            return State(INT_MAX, INT_MIN, 0, 0);
        }
        State left = solve(root -> left);
        State right = solve(root -> right);
        int max_sum = max(left.max_sum , right.max_sum);
        if( root -> val < right.min_val && root -> val > left.max_val ){
            int sum = root -> val + right.sum + left.sum;
            return State( min(root -> val, left.min_val ), max(root -> val, right.max_val), sum, max(sum, max_sum) );
        }else{
            return State(INT_MIN, INT_MAX, 0, max_sum );
        }
    }
    
    int maxSumBST(TreeNode* root) {
        State res = solve(root);
        return res.max_sum;
    }
};
