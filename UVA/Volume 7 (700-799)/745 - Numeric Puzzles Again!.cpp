/*****************************************
 ***Problema: Numeric Puzzles Again!
 ***ID: 745
 ***Juez: UVA
 ***Tipo: Simulation, Brute Force , BigNum
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 30
char line[ MAX ];
int n , sz;

struct Data{
    int digit , row , col;
    int s[ MAX ][ MAX ];
};

vector< Data > ady[ MAX ];

//extraemos el digito de la linea
int digito(){
    if( line[ 0 ] == '#' ) return -1;
    for( int i = 0 ; line[ i ] ; ++i ){
        if( line[ i ] >= '0' && line[ i ] <= '9' ){
            return line[ i ] - '0';
        }
    }
}

//agregamos como fila cada linea correcta
void actualizar( Data &table , int fila ){
    for( int i = 0 ; line[ i ] ; ++i ){
        if( isdigit( line[ i ] ) )
            table.s[ fila ][ i ] = line[ i ] - '0';
    }
}

//Rotamos 90 grados una tabla
Data rotar( Data table ){
    Data novo;
    int i , j , row = table.row, col = table.col;
    for( i = 0 ; i < row ; ++i ){
       for( j = 0 ; j < col ; ++j ){
           novo.s[ j ][ row - i - 1 ] = table.s[ i ][ j ];
       }
    }
    novo.digit = table.digit;
    novo.row = col;
    novo.col = row;
    return novo;
}

//Imprimirmos resultado
void imprimir( Data act ){
    for( int i = 0 ; i < act.row ; ++i ){
        for( int j = 0 ; j < act.col ; ++j ){
            printf("%d" , act.s[ i ][ j ] );
        }
        printf("\n");
    }
}


Data ans;
bool finish;
//Backtracking probando todas las posibilidades con las figuras rotadas
void solve( Data resp , int len ){
    if( len == sz ){
        ans = resp;
        finish = true;
        return;
    }
    int i , j , k , a , b;
    for( i = 0 ; i < ady[ len ].size() ; ++i ){
        Data act = ady[ len ][ i ];
        for( j = 0 ; j + act.row <= n ; ++j ){
            for( k = 0 ; k + act.col <= n ; ++k ){
                Data novo = resp;
                bool bad = false;
                //Verificamos si la posicion donde deseamos colocar ya fue ocupada por otra pieza
                for( a = 0 ; a < act.row ; ++a ){
                    for( b = 0 ; b < act.col ; ++b ){
                        if( act.s[ a ][ b ] == 0 ) continue;
                        if( novo.s[ a + j ][ b + k ] != 0  ){
                            a = act.row;
                            bad = true;
                            break;
                        }
                    }
                }

                if( bad ) continue;
                for( a = 0 ; a < act.row ; ++a ){
                    for( b = 0 ; b < act.col ; ++b ){
                        if( act.s[ a ][ b ] == 0 ) continue;
                        novo.s[ a + j ][ b + k ] = act.s[ a ][ b ];
                    }
                }
                solve( novo , len + 1 );
                if( finish ) return;
            }
        }
    }
}

//BIGNUM
const int MAXD = 105, DIG = 9, BASE = 1000000000;
const unsigned long long BOUND = numeric_limits <unsigned long long> :: max () - (unsigned long long) BASE * BASE;

struct bignum
{
    int D, digits [MAXD / DIG + 2];

    inline void trim ()
    {
        while (D > 1 && digits [D - 1] == 0)
            D--;
    }

    inline void init (long long x)
    {
        memset (digits, 0, sizeof (digits));
        D = 0;

        do
        {
            digits [D++] = x % BASE;
            x /= BASE;
        }
        while (x > 0);
    }

    inline bignum (long long x)
    {
        init (x);
    }

    inline bignum (int x = 0)
    {
        init (x);
    }

    inline bignum (char *s)
    {
        memset (digits, 0, sizeof (digits));
        int len = strlen (s), first = (len + DIG - 1) % DIG + 1;
        D = (len + DIG - 1) / DIG;

        for (int i = 0; i < first; i++)
            digits [D - 1] = digits [D - 1] * 10 + s [i] - '0';

        for (int i = first, d = D - 2; i < len; i += DIG, d--)
            for (int j = i; j < i + DIG; j++)
                digits [d] = digits [d] * 10 + s [j] - '0';

        trim ();
    }

    inline char *str ()
    {
        trim ();
        char *buf = new char [DIG * D + 1];
        int pos = 0, d = digits [D - 1];

        do
        {
            buf [pos++] = d % 10 + '0';
            d /= 10;
        }
        while (d > 0);

        reverse (buf, buf + pos);

        for (int i = D - 2; i >= 0; i--, pos += DIG)
            for (int j = DIG - 1, t = digits [i]; j >= 0; j--)
            {
                buf [pos + j] = t % 10 + '0';
                t /= 10;
            }

        buf [pos] = '\0';
        return buf;
    }

    inline bool operator < (const bignum &o) const
    {
        if (D != o.D)
            return D < o.D;

        for (int i = D - 1; i >= 0; i--)
            if (digits [i] != o.digits [i])
                return digits [i] < o.digits [i];

        return false;
    }

    inline bignum operator + (const bignum &o) const
    {
        bignum sum = o;
        int carry = 0;

        for (sum.D = 0; sum.D < D || carry > 0; sum.D++)
        {
            sum.digits [sum.D] += (sum.D < D ? digits [sum.D] : 0) + carry;

            if (sum.digits [sum.D] >= BASE)
            {
                sum.digits [sum.D] -= BASE;
                carry = 1;
            }
            else
                carry = 0;
        }

        sum.D = max (sum.D, o.D);
        sum.trim ();
        return sum;
    }
    inline bignum operator * (const bignum &o) const
    {
        bignum prod = 0;
        unsigned long long sum = 0, carry = 0;

        for (prod.D = 0; prod.D < D + o.D - 1 || carry > 0; prod.D++)
        {
            sum = carry % BASE;
            carry /= BASE;

            for (int j = max (prod.D - o.D + 1, 0); j <= min (D - 1, prod.D); j++)
            {
                sum += (unsigned long long) digits [j] * o.digits [prod.D - j];

                if (sum >= BOUND)
                {
                    carry += sum / BASE;
                    sum %= BASE;
                }
            }

            carry += sum / BASE;
            prod.digits [prod.D] = sum % BASE;
        }

        prod.trim ();
        return prod;
    }
};


//Obtenemos maximo rotando la figura y sumando valores, recordar son 20 digitos a lo mucho, por ello BigInteger
void getMax(){
    int i , j , k;
    Data aux = ans;
    bignum sum , maxi = bignum( 0 ) , num;
    for( k = 0 ; k < 4 ; ++k ){
        sum = bignum( 0 );
        for( i = 0 ; i < n ; ++i ){
            num = bignum( 0 );
            for( j = 0 ; j < n ; ++j ){
                num = num * 10 + bignum( aux.s[ i ][ j ] );
            }
            sum = sum + num;
        }
        if( maxi < sum ){
            maxi = sum;
            ans = aux;
        }
        aux = rotar( aux );
    }
    imprimir( ans );
}

int main(){
    int digit , aux , i , fila , col;
    while( scanf("%d" , &n ) , n ){
        scanf("%d" , &sz );
        gets( line );
        gets( line );
        for( i = 0 ; i < sz ; ++i ){
            Data table;
            memset( table.s , 0, sizeof( table.s ) );
            fila = col = 1;
            col = max( col , ( int )strlen( line ) );
            digit = digito();
            if( digit == -1 ) break;
            actualizar( table , 0 );
            while( gets( line ) ){
                aux = digito();
                if( aux != digit ) break;
                actualizar( table , fila++ );
                col = max( col , ( int )strlen( line ) );
            }
            table.row = fila; table.col = col; table.digit = digit;
            ady[ i ].push_back( table );
        }
        Data resp;
        resp.row = resp.col = n;
        memset( resp.s , 0 , sizeof( resp.s ) );
        finish = false;
        solve( resp , 0 );
        getMax();
        printf("\n");
        for( i = 0 ; i <= sz ; ++i ) ady[ i ].clear();
    }

    return 0;
}
