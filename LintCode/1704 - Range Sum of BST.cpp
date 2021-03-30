/*******************************************
 ***Problema: Range Sum of BST
 ***ID: 1704
 ***Juez: LintCode
 ***Tipo: Tree Traversal + Pruning
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root node
     * @param L: an integer
     * @param R: an integer
     * @return: the sum
     */
    int rangeSumBST(TreeNode * root, int L, int R) {
        if( root == NULL ) return 0;
        int sum = 0;        
        if( root -> val >= L && root -> val <= R ){
            sum += rangeSumBST(root -> left, L, R);
            sum += root -> val;
            sum += rangeSumBST(root -> right, L, R);
        }else if( root -> val < L ){
            sum += rangeSumBST(root -> right, L, R);
        }else if( root -> val > R ){
            sum += rangeSumBST(root -> left, L, R);
        }
        return sum;
    }
};
