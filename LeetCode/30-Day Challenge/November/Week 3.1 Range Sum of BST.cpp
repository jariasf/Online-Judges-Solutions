/*******************************************
 ***Problema: Range Sum of BST
 ***ID: Week3.1
 ***Juez: LeetCode
 ***Tipo: BST Traversal
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

// Solution 1
class Solution {
public:
    
    void inorder(TreeNode* root, int &res, int L, int R){
        if( root == NULL ) return;
        inorder(root -> left, res, L, R);
        if( root -> val >= L && root -> val <= R ) res += root -> val;
        inorder(root -> right, res, L, R);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        inorder(root, res, L, R);
        return res;
    }
};

// Solution 2
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if( root == NULL ) return 0;
        int sum = 0;
        if( root -> val >= low && root -> val <= high){
            sum += root -> val;
            sum += rangeSumBST(root -> left, low, high);
            sum += rangeSumBST(root -> right, low, high);            
        }else{
            if( root -> val > high ){
                sum += rangeSumBST(root -> left, low, high);
            }
            if( root -> val < low ){
                sum += rangeSumBST(root -> right, low, high);
            }
        }
        return sum;
    }
};
