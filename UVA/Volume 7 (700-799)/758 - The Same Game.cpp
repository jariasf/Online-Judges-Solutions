/*****************************************
 ***Problema: The Same Game
 ***ID: 758
 ***Juez: UVA
 ***Tipo: Simulation, flood fill
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
#define MAXR 10
#define MAXC 15
#define pii pair<int,int>
#define mp make_pair
char s[ MAXR + 5 ][ MAXC + 5 ] , aux[ MAXR + 5 ][ MAXC + 5];
int dx[] = { 0 ,  0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };
bool seen[ MAXR ][ MAXC ];

void rearrange(){
    for( int j = 0 ; j < MAXC ; ++j ){
        for( int i = MAXR - 1 ; i >= 0  ; --i ){
            if( s[i][j] == '.' ){
                for( int k = i - 1 ; k >= 0 ; --k ){
                    if( s[k][j] != '.' ){
                        s[i][j] = s[k][j];
                        s[k][j] = '.';
                        break;
                    }
                }
            }
        }
    }

    for( int j = 0 ; j < MAXC ; ++j ){
        int i = 0;
        for( ; i < MAXR ; ++i ){
            if( s[i][j] != '.')
                break;
        }
        if( i == MAXR ){
            int k;
            for( k = j + 1 ; k < MAXC ; ++k ){
                int w;
                for( w = 0 ; w < MAXR ; ++w ){
                    if( s[w][k] != '.'){
                        break;
                    }
                }
                if( w != MAXR ){
                    for( int v = 0 ; v < MAXR ; ++v ){
                        s[v][j] = s[v][k];
                        s[v][k] = '.';
                    }
                    break;
                }
            }
        }
    }
}


vector<pii> coord;
int flood( int x , int y , char color ){
    aux[ x ][ y ] = '.';
    coord.push_back( mp( x ,y ) );
    int ans = 1;
    for( int i = 0 ; i < 4 ; ++i ){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if( nx >= 0 && ny >= 0 && nx < MAXR && ny < MAXC && color == aux[ nx ][ ny ] ){
            ans += flood( nx , ny , color );
        }
    }
    return ans;
}

void printArray(){
    cout<<endl;
    for( int i = 0 ; i < MAXR; ++i){
        for( int j = 0 ; j < MAXC ; ++j ){
            cout<<s[i][j];
        }
        cout<<endl;
    }
}

struct Data{
    int x , y , cnt;
    Data(){};
    Data( int xx , int yy , int c ): x(xx) , y(yy) , cnt(c){}
};

bool cmp( Data d1 , Data d2 ){
    return (d1.cnt > d2.cnt) || (d1.cnt == d2.cnt && d1.y < d2.y )
            || ( d1.cnt == d2.cnt && d1.y == d2.y && d1.x > d2.x );
}

vector<Data> countBalls( int xini ){
    vector<Data> countMap;
    memcpy( aux , s , sizeof( s ) );
    for( int i = xini ; i < MAXR ; ++i ){
        for( int j = 0 ; j < MAXC ; ++j ){
            if( aux[i][j] != '.' ){
                coord.clear();
                int cnt = flood( i , j , aux[i][j] );
                for( int k = 0 ; k < coord.size() ; ++k ){
                    int x = coord[k].first , y = coord[k].second;
                    countMap.push_back( Data(x , y , cnt ));
                }
            }
        }
    }

    sort( countMap.begin() , countMap.end() , cmp );
    return countMap;
}

void removeBalls( int x , int y , char color ){
    s[x][y] = '.';
    for( int i = 0 ; i < 4 ; ++i ){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if( nx >= 0 && ny >= 0 && nx < MAXR && ny < MAXC && color == s[ nx ][ ny ] ){
            removeBalls( nx , ny , color );
        }
    }
}


int main(){
    int t, moves , points , ans , xini, remain;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        if( q - 1 )
            printf("\n");
        for( int i = 0 ; i < MAXR && scanf("%s" , s[i] ) ; ++i );
        ans = 0;
        printf("Game %d:\n\n" , q );
        xini = 0;
        moves = 0;
        remain = 0;
        while( true ){
            vector<Data> countMap = countBalls(xini);
            if( countMap.size() == 0 ){ ans+=1000; break;}
            int x = countMap[0].x, y = countMap[0].y, cnt = countMap[0].cnt;
            if( cnt <= 1 ){
                remain += countMap.size();
                break;
            }

            char color = s[ x ][ y ];
            removeBalls( x , y , s[ x ][ y ] );
            rearrange();
            moves++;
            points = ( cnt - 2 ) * ( cnt - 2 );
            x = MAXR - x; y++;
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n" , moves , x , y , cnt , color , points );
            ans += points;
        }

        printf("Final score: %d, with %d balls remaining.\n" , ans , remain );
    }

    return 0;
}
