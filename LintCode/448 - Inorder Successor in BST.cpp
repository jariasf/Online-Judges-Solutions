/*******************************************
 ***Problema: Inorder Successor in BST
 ***ID: 448
 ***Juez: LintCode
 ***Tipo: Recursion
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
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
	//Iterative
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        TreeNode *suc = NULL;
        while(root){
            if( root -> val > p -> val ){
                suc = root;
                root = root -> left;
            }else{
                root = root -> right;
            }
        }
        return suc;
    }
	
	//Recursive
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if( root == NULL )
            return NULL;
        if( p -> val >= root -> val ){
            return inorderSuccessor(root -> right, p);
        }else{
            TreeNode* tmp = inorderSuccessor(root -> left, p);
            if( tmp == NULL ) return root;
            return tmp;
        }
    }
};
