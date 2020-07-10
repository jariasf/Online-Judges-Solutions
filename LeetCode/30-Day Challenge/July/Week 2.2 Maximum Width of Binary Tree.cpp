/*******************************************
 ***Problema: Maximum Width of Binary Tree
 ***ID: Week2.2
 ***Juez: LeetCode
 ***Tipo: BFS | DFS
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
    typedef unsigned long long LL;
    #define pii pair<TreeNode*, pair<int,LL> >
    #define mp make_pair
    int widthOfBinaryTree(TreeNode* root) {
        if( root == NULL ) return 0;
        vector<LL> left, right;
        queue<pii> Q;
        Q.push(mp(root, mp(0, 1)));
        while( !Q.empty() ){
            pii cur = Q.front(); Q.pop();
            
            if( left.size() == cur.second.first )
                left.push_back(cur.second.second);
            else
                left[cur.second.first] = min(left[cur.second.first], cur.second.second);
            
            if( right.size() == cur.second.first )
                right.push_back(cur.second.second);
            else
                right[cur.second.first] = max(right[cur.second.first], cur.second.second);
            
            
            if( cur.first -> left )
                Q.push(mp(cur.first -> left, mp(cur.second.first + 1, cur.second.second * 2)));
            
            if( cur.first -> right )
                Q.push(mp(cur.first -> right, mp(cur.second.first + 1, cur.second.second * 2 + 1)));
        }
        
        int sz = min(left.size(), right.size());
        LL result = 1;
        for( int i = 0 ; i < sz; ++i)
            result = max( result, right[i] - left[i] + 1);
        return result;        
    }
};
