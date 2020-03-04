/*******************************************
 ***Problem: Sum of Two
 ***Judge: CodeSignal
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

bool sumOfTwo(std::vector<int> a, std::vector<int> b, int v) {
    int na = a.size(), nb = b.size();
    unordered_set<int> hash;
    for( int i = 0 ; i < na ; ++i ) hash.insert(a[i]);
    for( int i = 0 ; i < nb ; ++i ){
        if( hash.find( v - b[i] ) != hash.end() )
            return true;
    } 
    return false;
}

