/*******************************************
 ***Problema: Find Duplicate Subtrees
 ***ID: Week 4.7
 ***Juez: LeetCode
 ***Tipo: Tree traversal + Hashing
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
class Solution {
public:
    unordered_map<string, int> hash;
    string preorder(TreeNode* root, vector<TreeNode*> &res){
        if( root == nullptr ) return "";
        string cur = to_string(root -> val)+"#";
        cur += preorder(root -> left, res);
        cur += "#";
        cur += preorder(root -> right, res);
        if( hash[cur] == 1 ){
            res.push_back(root);
        }
        hash[cur]++;
        return cur;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        preorder(root, res);
        return res;
    }
};
