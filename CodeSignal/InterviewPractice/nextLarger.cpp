/*******************************************
 ***Problema: Next Larger
 ***Juez: CodeSignal
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

std::vector<int> nextLarger(std::vector<int> a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> S;
    for( int i = n - 1 ; i >= 0 ; --i ){
        while( !S.empty() && a[i] >= S.top() ){
            S.pop();
        }
        if( !S.empty() )
            res[i] = S.top();
        S.push(a[i]);
    }
    return res;
}
