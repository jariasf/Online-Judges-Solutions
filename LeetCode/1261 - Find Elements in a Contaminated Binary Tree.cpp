/*******************************************
 ***Problema: Find Elements in a Contaminated Binary Tree
 ***ID: 1261
 ***Juez: LeetCode
 ***Tipo: Tree Traversal
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
class FindElements {
public:
    unordered_set<int> seen;
    
    void traverse(TreeNode* root, int id){
        if( root == NULL) return;
        root -> val = id;
        seen.insert(id);
        traverse(root -> left, id * 2 + 1);
        traverse(root -> right, id * 2 + 2);
    }
    
    FindElements(TreeNode* root) {
        seen.clear();
        traverse(root, 0);
    }
    
    bool find(int target) {
        return seen.find(target) != seen.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
