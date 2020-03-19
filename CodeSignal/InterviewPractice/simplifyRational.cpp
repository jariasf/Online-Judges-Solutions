/*******************************************
 ***Problem: Simplify Rational
 ***Judge: CodeSignal
 ***Type: GCD
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

int gcd(int a, int b){
    if( b == 0 ) return a;
    return gcd(b, a % b);
}

std::vector<int> simplifyRational(int numerator, int denominator) {
    bool negative = (numerator > 0 && denominator < 0) || 
                    (numerator < 0 && denominator > 0);
    
    numerator = abs(numerator);
    denominator = abs(denominator);

    int _gcd = gcd(numerator, denominator);
    numerator /= _gcd;
    denominator /= _gcd;

    if( negative )
        numerator *= -1;

    return {numerator, denominator};
}

