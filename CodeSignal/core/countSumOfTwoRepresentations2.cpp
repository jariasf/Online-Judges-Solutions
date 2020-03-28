/*******************************************
 ***Problem: Count Sum Of Two Representations 2
 ***Judge: CodeSignal
 ***Type: Math
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// O(1)
int countSumOfTwoRepresentations2(int n, int l, int r) {
    int N = n - l;
    if( N < l ) return 0;

    if( N > r ){
        l += N - r;
        N = r;
    }    
    int cnt = (N - l)/2 + 1;
    return cnt;
}

// O(r - l)
int countSumOfTwoRepresentations2(int n, int l, int r) {
    int cnt = 0;
    for( int A = l ; A <= n - A ; ++A ){
        if( n - A <= r ) cnt++;
    }
    return cnt;
}



