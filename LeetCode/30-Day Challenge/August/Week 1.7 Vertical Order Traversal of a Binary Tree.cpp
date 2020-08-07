/*******************************************
 ***Problema: Vertical Order Traversal of a Binary Tree
 ***ID: Week1.7
 ***Juez: LeetCode
 ***Tipo: DFS|BFS + Sorting
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
    #define pii pair<int, int>
    #define mp make_pair
    map<int, vector<pii> > hash;
    
    void traverse(TreeNode* root, int id, int depth = 0){
        if( root == NULL ) return;
        hash[id].push_back(mp(depth,root -> val));
        traverse(root -> left, id - 1, depth + 1);
        traverse(root -> right, id + 1, depth + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        hash.clear();
        vector<vector<int> > res;
        traverse(root, 0);
        for( auto it: hash ){
            sort(it.second.begin(), it.second.end());
            vector<int> tmp;
            for( pii p: it.second ){
                tmp.push_back(p.second);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
