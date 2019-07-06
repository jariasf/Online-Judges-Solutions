/*******************************************
 ***Problema: Complete Binary Tree Inserter
 ***ID: 919
 ***Juez: LeetCode
 ***Tipo: Binary Tree Node, BFS
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
class CBTInserter {
public:
    int parent_pos;
    vector<TreeNode*> parents, children;
    TreeNode* _root;
    void fillChildren(){
        children.clear();
        for( int i = 0 ; i < parents.size(); ++i ){
            TreeNode* current = parents[i];
            if( current -> left ){
                children.push_back(current -> left);
            }
            if( current -> right ){
                children.push_back(current -> right);
            }
        }
        parents = children;
        parent_pos = 0;
    }
    
    CBTInserter(TreeNode* root) {
        _root = root;
        parents.clear();
        children.clear();
        parent_pos = 0;
        if( root != NULL ){
            queue<TreeNode*> Q;        
            Q.push(root);
            int level = 0;
            while( !Q.empty() ){
                int nodes = Q.size();            
                if( nodes == 1<<level ){
                    parents.clear();
                    for( int i = 0 ; i < nodes; ++i ){
                        TreeNode* current = Q.front();
                        parents.push_back( current );
                        Q.pop();
                    }
                    for( int i = 0 ; i < nodes; ++i ){
                        TreeNode* current = parents[i];
                        if( current -> left ) Q.push(current -> left);
                        if( current -> right ) Q.push(current -> right);
                        if( current -> left == NULL || current -> right == NULL ){
                            parent_pos = i;
                            break;
                        }
                    }
                }else{
                    break;
                }
                level++;
            }
        }
    }
    
    int insert(int v) {
        TreeNode* current = parents[parent_pos];
        if( current -> left == NULL ){
            current -> left = new TreeNode(v);
            return current -> val;
        }else if( current -> right == NULL ){
            current -> right = new TreeNode(v);
            parent_pos++;
            if( parent_pos == parents.size() ){
                fillChildren();
            }
            return current -> val;
        }
    }
    
    TreeNode* get_root() {
        return _root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
