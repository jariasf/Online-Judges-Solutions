/*******************************************
 ***Problem: Insert Bit
 ***Judge: CodeSignal
 ***Type: BitMasks
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

int insertBits(int n, int a, int b, int k) {
    int res = n;
    for( int i = a ; i <= b ; ++i ){
        int bit = k & 1<<(i - a);
        res ^= (res ^ -bit) & (1<<i);
    }
    return res;
}
