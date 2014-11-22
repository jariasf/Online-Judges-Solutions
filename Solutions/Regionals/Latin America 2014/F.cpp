/*****************************************
 ***Problema: Fence the vegetables
 ***Tipo: Sweep Line
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
#define pii pair<int ,int>
#define mp make_pair
#define pb push_back
#define MAX 100005
pii points[ 4 * MAX ];
int dx[4] = { 0 , 0 , 1 , 1 };
int dy[4] = { 0 , 1 , 1 , 0 };

int main(){
    int n, x, y, minX, maxX, minY, maxY, tmpYmin, tmpYmax;
    long long perimeter, area;

    while( scanf("%d" , &n ) != EOF ){
        perimeter = area = 0;
        minX = minY = 1<<30;
        maxX = maxY = 0;
        for( int i = 0 ; i < n && scanf("%d %d" , &x , &y ) ; ++i ){
            for( int j = 0 ; j < 4 ; ++j ){
                int nx = dx[ j ] + x;
                int ny = dy[ j ] + y;
                points[ 4 * i + j ] = mp( nx , ny );
                minX = min( minX , nx );
                minY = min( minY , ny );
                maxX = max( maxX , nx );
                maxY = max( maxY , ny );
            }
        }

        perimeter = ( maxX -  minX + 1) * 2LL + ( maxY - minY + 1) * 2LL;
        area = ( maxX -  minX + 1) * (long long)( maxY - minY + 1);
        sort( points , points + 4 * n );
        vector<int> X , yMin, yMax;

        for( int i = 0 ; i < 4 * n ; ++i ){
            int j = i + 1;
            X.pb( points[i].first );
            tmpYmin = points[i].second; tmpYmax = tmpYmin;
            while( j < n && points[i].first == points[j].first ){
                tmpYmin = min( tmpYmin , points[j].second );
                tmpYmax = max( tmpYmax , points[j].second );
                j++;
            }
            yMin.pb(tmpYmin); yMax.pb(tmpYmax);
            i = j - 1;
        }

        int last = 1<<30, sz = X.size();
        for( int i = 0 ; i < sz - 1 ; ++i ){
            last = min( last , maxY - yMax[i] );
            area -= ( X[ i + 1 ] - X[ i ] ) * (long long) last;
            if( i + 1 < sz ){
                yMin[ i + 1 ] = min( yMin[ i + 1 ] , maxY - last );
            }
        }

        last = 1<<30;
        for( int i = sz - 1 ; i >= 1 ; --i ){
            last = min( last , maxY - yMax[i] );
            area -= ( X[ i ] - X[ i - 1 ] ) * (long long) last;
            if( i - 1 >= 0 ){
                yMin[ i - 1 ] = min( yMin[ i - 1 ] , maxY - last );
            }
        }

        last = 1<<30;
        for( int i = 0 ; i < sz - 1 ; ++i ){
            last = min( last , yMin[i] - minY );
            area -= ( X[ i + 1 ] - X[ i ] ) * (long long) last;
        }

        last = 1<<30;
        for( int i = sz - 1 ; i >= 1 ; --i ){
            last = min( last , yMin[i] - minY );
            area -= ( X[ i ] - X[ i - 1 ] ) * (long long) last;
        }

        printf("%lld %lld\n" , perimeter, area );
    }

    return 0;
}
