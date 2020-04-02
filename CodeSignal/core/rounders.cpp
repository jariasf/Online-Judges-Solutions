/*******************************************
 ***Problem: Rounders
 ***Judge: CodeSignal
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// Simple
int rounders(int n ){
    int p = 1;
    while(n > 10){
        n = (n + 5)/10;
        p *= 10;
    }
    return p * n;
}

// Simulation
int rounders(int n) {
    int result = 0, p = 1;
    int carry = 0;
    while(n){
        int val = n % 10 + carry;
        if( val < 5 ){
            carry = 0;
        }else{
            carry = 1;
        }
        p *= 10;
        n /= 10;
        result = val;
    }
    return result * p/10;
}

