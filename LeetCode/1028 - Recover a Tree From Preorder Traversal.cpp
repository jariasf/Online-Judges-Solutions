/***************************************************
 ***Problema: Recover a Tree From Preorder Traversal
 ***ID: 1028
 ***Juez: LeetCode
 ***Tipo: Data Structures + Parsing
 ***Autor: Jhosimar George Arias Figueroa
 **************************************************/

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
    #define pii pair<int,int>
    #define mp make_pair
    unordered_map<int, vector<TreeNode*> > hash;
    string s;
    
    pii getNextInt(int pos){
        int val = 0;
        while( pos < s.size() && s[pos] >= '0' && s[pos] <= '9' ){
            val = val * 10 + s[pos] - '0';
            pos++;
        }
        return mp(val, pos);
    }
    
    void solve(int pos){            
        if( pos == s.size() ) return;
        
        int next_depth = 0;
        for( int i = pos; i < s.size() && s[i] == '-'; ++i ){
            next_depth++;
        }
        
        pii p = getNextInt(pos + next_depth);
        int next_val = p.first;
        int next_pos = p.second;
        vector<TreeNode*> v = hash[next_depth - 1];

        for( int i = v.size() - 1; i >= 0 ; --i ){
            TreeNode* cur = v[i];
            if( cur -> left == NULL ){
                cur -> left = new TreeNode(next_val);
                hash[next_depth].push_back(cur -> left);
                break;
            }else if( cur -> right == NULL ){
                cur -> right = new TreeNode(next_val);
                hash[next_depth].push_back(cur -> right);
                break;
            }
        }
        solve(next_pos);
    }
    
    TreeNode* recoverFromPreorder(string S) {
        s = S;
        hash.clear();
        pii p = getNextInt(0);
        int next_val = p.first;
        int next_pos = p.second;
        TreeNode* root = new TreeNode(next_val);
        hash[0].push_back(root);
        solve(next_pos);
        return root;
    }
};
