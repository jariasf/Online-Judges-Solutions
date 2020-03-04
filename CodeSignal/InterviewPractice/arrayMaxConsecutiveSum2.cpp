/*******************************************
 ***Problema: Array Max Consecutive Sum 2
 ***Juez: CodeSignal
 ***Tipo: Kadane's Algorithm
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

int arrayMaxConsecutiveSum2(std::vector<int> v) {
    int n = v.size();
    int maximum = -INT_MAX, sum = 0;
    for( int i = 0 ; i < n ; ++i ){
        sum += v[i];
        if( sum > maximum ){
            maximum = sum;
        }
        if( sum < 0 ) sum = 0;
    }
    return maximum;
}

