/*******************************************
 ***Problema: Maximum Level Sum of a Binary Tree    
 ***ID: 1161
 ***Juez: LeetCode
 ***Tipo: Binary Trees, DFS | BFS
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
    #define MAX 10005
    #define pii pair<TreeNode*, int>
    #define mp make_pair
    int maxLevelSum(TreeNode* root) {
        queue<pii> Q;
        Q.push(mp(root, 0));
        vector<int> depth(MAX);
        depth.push_back(root -> val);

        while( !Q.empty() ){
            pii p = Q.front(); Q.pop();
            TreeNode* cur = p.first;
            int d = p.second;
            if( cur -> left ){
                depth[ d + 1 ]+= cur -> left -> val;
                Q.push( mp(cur -> left, d + 1));
            }

            if( cur -> right ){
                depth[ d + 1] += cur -> right -> val;
                Q.push(mp(cur -> right, d + 1));
            }

        }

        int maxi = 0;
        int index = 0;
        for( int i = 0 ; i < MAX ; ++i ){
            if( depth[i] > maxi ){
                maxi = depth[i];
                index = i;
            }
        }
        return index + 1;
    }
};
