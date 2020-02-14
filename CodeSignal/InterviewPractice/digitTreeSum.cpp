/*******************************************
 ***Problema: Digit Tree Sum
 ***Juez: CodeSignal
 ***Tipo: Binary Tree Traversal
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
long long digitTreeSum(Tree<int> * t, long long sum= 0) {
    if( t == NULL ) return 0;
    if( t -> left == NULL && t -> right == NULL)
        return sum * 10 + t -> value;
    long long total = 0;
    total += digitTreeSum(t -> left, sum * 10 + t -> value);
    total += digitTreeSum(t -> right, sum * 10 + t -> value);
    return total;
}
