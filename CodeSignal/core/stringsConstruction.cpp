/*******************************************
 ***Problem: String Construction
 ***Judge: CodeSignal
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

int stringsConstruction(std::string a, std::string b) {
    vector<int> hash_b(26), hash_a(26);
    for( int i = 0 ; i < b.size(); ++i ) hash_b[b[i] - 'a']++;
    for( int i = 0 ; i < a.size(); ++i ) hash_a[a[i] - 'a']++;
    int mini = INT_MAX;
    for( int i = 0 ; i < 26 ; ++i ){
        if( hash_a[i] > 0 ){
            mini = min(hash_b[i]/hash_a[i], mini);
        }
    }
    return mini;
}


