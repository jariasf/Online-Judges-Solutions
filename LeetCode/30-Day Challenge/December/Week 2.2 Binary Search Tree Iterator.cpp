/*******************************************
 ***Problema: Binary Search Tree Iterator
 ***ID: Week2.2
 ***Juez: LeetCode
 ***Tipo: BST Iterator
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
class BSTIterator {
public:
    TreeNode *pLeft;
    stack<TreeNode*> S;
    BSTIterator(TreeNode *root) {
        pLeft = root;
        while( pLeft ){
            S.push(pLeft);
            pLeft = pLeft -> left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        bool b = (!S.empty() || pLeft);
        if(b){
            while(pLeft){
                S.push(pLeft);
                pLeft = pLeft -> left;
            }
        }
        return b;
    }

    /** @return the next smallest number */
    int next() {
        pLeft = S.top(); S.pop();
        int val = pLeft -> val;
        pLeft = pLeft -> right;
        return val;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
