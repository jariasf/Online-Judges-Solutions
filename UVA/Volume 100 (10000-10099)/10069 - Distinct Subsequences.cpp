/*****************************************
 ***Problema: Distinct Subsequences
 ***ID: 10069
 ***Juez: UVA
 ***Tipo: DP
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

    inline bool operator == (const bignum &o) const
    {
        if (D != o.D)
            return false;

        for (int i = 0; i < D; i++)
            if (digits [i] != o.digits [i])
                return false;

        return true;
    }

    inline bignum operator << (int p) const
    {
        bignum temp;
        temp.D = D + p;

        for (int i = 0; i < D; i++)
            temp.digits [i + p] = digits [i];

        for (int i = 0; i < p; i++)
            temp.digits [i] = 0;

        return temp;
    }

    inline bignum operator >> (int p) const
    {
        bignum temp;
        temp.D = D - p;

        for (int i = 0; i < D - p; i++)
            temp.digits [i] = digits [i + p];

        for (int i = D - p; i < D; i++)
            temp.digits [i] = 0;

        return temp;
    }

    inline bignum range (int a, int b) const
    {
        bignum temp = 0;
        temp.D = b - a;

        for (int i = 0; i < temp.D; i++)
            temp.digits [i] = digits [i + a];

        return temp;
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
};

#define MAXX 10005
#define MAXZ 105
char x[ MAXX ] ,z[ MAXZ ];
bignum dp[ MAXX ][ MAXZ] , seen[ MAXX ][ MAXZ ];
int lx , lz;
bignum solve( int lenx , int lenz ){
    if( lenz == lz ) return bignum( 1 );
    if( lenx == lx ) return bignum( 0 );
    if( seen[ lenx ][ lenz ] == bignum( 1 ) ) return dp[ lenx ][ lenz ];
    bignum ans = 0;
    if( x[ lenx ] == z[ lenz ] ) ans = ans + solve( lenx + 1 , lenz + 1 ) + solve( lenx + 1 , lenz );
    else ans = ans + solve( lenx + 1 , lenz );
    seen[ lenx ][ lenz ] = 1;
    return dp[ lenx ][ lenz ] = ans;
}

int main(){
    int t , i,  j;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%s%s" , &x , &z ) ){
        lx = strlen( x ); lz = strlen( z );
        for( i = 0 ; i <= lx ; ++i )
            for( j = 0 ; j <= lz ; ++j ){
                seen[ i ][ j ] = bignum( 0 );
            }
        printf("%s\n" , solve( 0 , 0 ).str() );
    }

    return 0;
}
