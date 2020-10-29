/*******************************************
 ***Problema: Serialize and Deserialize BST
 ***ID: Week2.2
 ***Juez: LeetCode
 ***Tipo: Binary Search
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if( root == NULL ) return result;
        queue<TreeNode*> Q;
        Q.push(root);
        result.append( to_string(root -> val) );
        while( !Q.empty() ){
            TreeNode* current = Q.front(); Q.pop();
            result.append(" ");
            if( current -> left ){
                result.append( to_string(current -> left -> val) );
                Q.push(current -> left);
            }else
                result.append(to_string(INT_MIN));
                
            result.append(" ");
            if( current -> right ){
                result.append( to_string(current -> right -> val) );
                Q.push(current -> right);
            }else
                result.append(to_string(INT_MIN));    
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if( data.size() == 0 ) return NULL;
        
        stringstream ss(data);
        int current;
        vector<int> tree;
        while( ss>>current ){
            tree.push_back( current );
        }
        
        TreeNode* root = new TreeNode(tree[0]);
        int n = tree.size();
        queue<TreeNode*> Q;
        Q.push(root);
        int index = 0;
        while( !Q.empty() ){
            TreeNode* current = Q.front(); Q.pop();
            if( index + 1 < n ){
                if( tree[ index + 1] != INT_MIN ){
                    current -> left = new TreeNode(tree[ index + 1]);
                    Q.push( current -> left );
                }
            }
            if( index + 2 < n ){
                if( tree[ index + 2 ] != INT_MIN ){
                    current -> right = new TreeNode(tree[ index + 2]);
                    Q.push( current -> right );
                }
            }
            index += 2;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
