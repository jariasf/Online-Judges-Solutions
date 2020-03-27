/*******************************************
 ***Problem: Digits Product
 ***Judge: CodeSignal
 ***Type: Math
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

int digitsProduct(int product) {
    if( product == 0 ) return 10;
    if( product == 1 ) return 1;
    
    vector<int> v;
    for( int i = 9 ; i >= 2 ; --i ){
        while( product % i == 0 ){
            product /= i;
            v.push_back(i);
        }
    }
    if( product > 1 ) return -1;
    
    int res = 0;
    for( int i = v.size() - 1 ; i >= 0 ; --i ){
        res = res * 10 + v[i];
    }
    return res;
}


