/*****************************************
 ***Problema: Roman Numerals
 ***ID: 12397
 ***Juez: UVA
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int  decimal2roman(int input)
{
    char roman[ 13 ][ 3 ] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int decimal[13] =  {1000,  900, 500,  400, 100,   90,  50,   40,  10,   9,    5,    4,   1};
    int val = 0;
    for(int i = 0 ; i < 13 ; ++i )
    {
        while( input >= decimal[ i ] )
        {
            input -= decimal[ i ];
            for( int j = 0 ; roman[ i ][ j ] ; ++j ){
                if( roman[ i ][ j ] == 'I' ) val ++;
                else if( roman[ i ][ j ] == 'V' ) val += 2;
                else if( roman[ i ][ j ] == 'X' ) val += 2;
                else if( roman[ i ][ j ] == 'L' ) val += 2;
                else if( roman[ i ][ j ] == 'C' ) val += 2;
                else if( roman[ i ][ j ] == 'D' ) val += 3;
                else if( roman[ i ][ j ] == 'M' ) val += 4;
            }
        }
    }
    return val;
}


int main(){
    int n;
    while( scanf("%d" , &n ) == 1 ){
        printf("%d\n" , decimal2roman( n ) );
    }

    return 0;
}
