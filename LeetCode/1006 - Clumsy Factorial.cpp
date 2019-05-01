/*******************************************
 ***Problema: Clumsy Factorial
 ***ID: 1006
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int clumsy(int N) {
        long long result = N;
        
        int aux = 0;
        if( N <= 4 ){
            for( long long i = N - 1 ; i >= 1 ; --i ){
                if( aux == 0 ) result *= i;
                else if( aux == 1 ) result /= i;
                else if( aux == 2 ) result += i;
                else result -= i;
                aux = (aux + 1) % 4;
            }
            return result;
        }
        
        aux = 0;
        long long i = N - 1;
        for( int j = 0 ; i >= 1 && j < 3 ; --i, ++j ){
            if( aux == 0 ) result *= i;
            else if( aux == 1 ) result /= i;
            else if( aux == 2 ) result += i;
            else result -= i;
            aux = (aux + 1) % 4;
        }
        
        for( ; i >= 1 ; ){    
            long long v = -i--;
            aux = 0;
            for( int j = 0 ; i >= 1 && j < 3 ; --i, ++j ){
                if( aux == 0 ) v *= i;
                else if( aux == 1 ) v /= i;
                else if( aux == 2 ) v += i;
                else v -= i;
                aux = (aux + 1) % 4;
            }
            
            result += v;
        }
        return result;
    }
};
