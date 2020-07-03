/*******************************************
 ***Problema: Binary Tree Level Order Traversal II
 ***ID: Week1.2
 ***Juez: LeetCode
 ***Tipo: BFS
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
    #define pii pair<TreeNode*, int>
    #define mp make_pair
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if( root == NULL ) return res; 
        queue<pii> Q;
        Q.push(mp(root, 0));
        while(!Q.empty()){
            pii p = Q.front(); Q.pop();
            TreeNode* cur = p.first;
            if( res.size() < p.second + 1 )
                res.push_back({cur -> val});
            else
                res[p.second].push_back(cur -> val);
            if( cur && cur -> left )
                Q.push(mp(cur -> left, p.second + 1));

            if( cur && cur -> right )
                Q.push(mp(cur -> right, p.second + 1));            
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
