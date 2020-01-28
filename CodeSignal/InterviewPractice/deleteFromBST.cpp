/*******************************************
 ***Problema: Delete From BST
 ***Juez: CodeSignal
 ***Tipo: BST
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

bool isLeaf(Tree<int> *node){
    return node -> left == NULL && node -> right == NULL;
}

int getPredecessorVal(Tree<int> *root){
    Tree<int> *parent = root;
    Tree<int> *tmp = root -> left;
    if( tmp -> right == NULL ){
        int val = tmp -> value;
        root -> left = tmp -> left;
        return val;
    }
    while(tmp && tmp -> right){
        parent = tmp;
        tmp = tmp -> right;
    }
    parent -> right = tmp -> left;
    return tmp -> value;
}

Tree<int>* deleteNode(Tree<int> *root, int val){
    if( root == NULL ) return NULL;
    if( root -> value == val ){   
        if( isLeaf(root) ) return NULL;
        if( root -> left != NULL ){
            root -> value = getPredecessorVal(root);
        }else if(root -> right != NULL){
            return root -> right;
        }else
            return NULL;
    }else if( root -> value > val ){
        root -> left = deleteNode(root -> left, val);
    }else{
        root -> right = deleteNode(root -> right, val);
    }
    return root;
}

Tree<int> * deleteFromBST(Tree<int> * root, std::vector<int> queries) {
    for( int i = 0 ; i < queries.size(); ++i ){
        root = deleteNode(root, queries[i]);
    }
    return root;
}

