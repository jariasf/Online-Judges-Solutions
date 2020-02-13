/*******************************************
 ***Problema: Most Frequent Sum
 ***Juez: CodeSignal
 ***Tipo: Binary Tree Traversal + Hashing
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

unordered_map<int, int> counter;

int sumTree(Tree<int> *root){
    if( root == NULL ) return 0;
    int sum = root -> value + sumTree(root -> left) + sumTree(root -> right);
    counter[sum]++;
    return sum;
}

std::vector<int> mostFrequentSum(Tree<int> * t) {
    counter.clear();
    sumTree(t);
    int maximum = -1<<30;

    for(auto &it:counter){
        if( it.second > maximum ){
            maximum = it.second;
        }
    }

    vector<int> result;
    for(auto &it:counter){
        if( it.second == maximum ){
            result.push_back(it.first);
        }
    }
    sort(result.begin(), result.end());
    return result;
}
