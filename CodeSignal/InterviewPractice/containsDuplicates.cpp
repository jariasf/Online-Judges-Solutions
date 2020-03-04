/*******************************************
 ***Problema: Contains Duplicates
 ***Juez: CodeSignal
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

bool containsDuplicates(std::vector<int> a) {
    int n = a.size();
    unordered_set<int> hash;
    for( int i = 0 ; i < n ; ++i ){
        if( hash.find(a[i]) != hash.end() ) return true;
        hash.insert(a[i]);
    }
    return false;
}
