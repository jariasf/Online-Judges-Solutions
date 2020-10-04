/*******************************************
 ***Problema: Even Odd Tree
 ***ID: 1609
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int depth = 0;
        while( !Q.empty() ){
            vector<int> v;
            int sz = Q.size();
            for( int i = 0 ;i  <sz ; ++i ){
                TreeNode* cur = Q.front(); Q.pop();
                v.push_back(cur->val);
                if( cur -> left ){
                    Q.push(cur -> left);
                }
                if( cur -> right )
                    Q.push(cur -> right);
            }
            if( depth & 1 ){
                if( v.size() > 0 && v[0] % 2 != 0 ) return false;
                for( int i = 1 ; i < v.size(); ++i ){
                    if( (v[i] & 1) || v[i] >= v[i - 1]) return false;
                }
            }else{
                if( v.size() > 0 && v[0] % 2 == 0 ) return false;
                for( int i = 1 ; i < v.size(); ++i ){
                    if( (v[i] % 2 == 0) || v[i] <= v[i - 1]) return false;
                }
            }
            
            depth++;
        }
        return true;
    }
};
