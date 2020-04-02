/*******************************************
 ***Problem: Numbers Grouping
 ***Judge: CodeSignal
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

int numbersGrouping(std::vector<int> a) {
    int n = a.size();
    unordered_map<int, int> hash;
    for( int i = 0 ; i < n ; ++i ){
        hash[ (a[i] - 1)/10000 ]++;
    }
    return hash.size() + n;
}
