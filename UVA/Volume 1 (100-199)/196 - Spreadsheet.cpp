#include <stdio.h>
#include <algorithm>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;
#define MAXC 20000
#define MAXR 1005
string toStr(int n){string s;ostringstream buffer;buffer<<n;s=buffer.str();return s;}
int toInt(string str){int n;istringstream buffer(str);buffer>>n;return n;}

int h , w;
string ady[ MAXR ][ MAXC ];
int res[ MAXR ][ MAXC ];

map<string , int > col;

void gen(){
    string s;
    int cnt = 0;

    for( int i = 'A' ; i <= 'Z' ; ++i ){
        s = (char)(i);
        col[s] = cnt++;
    }

    for( int i = 'A' ; i <= 'Z' ; ++i ){
        for( int j = 'A' ; j <= 'Z' ; ++j ){
            s = (char)(i);
            s += (char)(j);
            col[s] = cnt++;
        }
    }

    for( int i = 'A' ; i <= 'Z' ; ++i ){
        for( int j = 'A' ; j <= 'Z' ; ++j ){
            for( int k = 'A' ; k <= 'Z' ; ++k ){
                s = (char)(i);
                s += (char)(j);
                s += (char)k;
                col[s] = cnt++;
            }
        }
    }
}

bool isValid( char c ){
    return ( c >= '0' && c <= '9' ) || ( c >= 'A' && c <= 'Z');
}

int solve( int r , int c , string s ){

    if( s[0] != '=' ){
        return res[r][c];
    }
    if( res[r][c] != -1<<30 )
        return res[r][c];

    int sum = 0;
    for( int i = 0 ; i < s.length() ; ++i ){
        if( !isValid(s[i] ) ){
            s[i] = ' ';
        }
    }
    stringstream ss(s);
    string cell;
    while( ss>>cell ){
        string colVal = "";
        int row = 0;
        for( int i = 0 ; i < cell.length() ; ++i ){
            if( cell[i] >= '0' && cell[i] <= '9' ){
                row = 10*row + cell[i] - '0';
            }else
                colVal += cell[i];
        }
        row--;
        int column = col[colVal];
        sum += solve( row , column , ady[ row ][ column ] );
    }
    return res[r][c] = sum;
}


int main(){
    gen();
    int t;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d %d" , &w , &h ) ){

        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w && cin>>ady[i][j] ; ++j ){
                if( ady[i][j][0] == '=' ){
                    res[i][j] = -1<<30;
                }else{
                    res[i][j] = toInt(ady[i][j]);
                }
            }
        }

        bool first;
        for( int i = 0 ; i < h ; ++i ){
            first = true;
            for( int j = 0 ; j < w ; ++j ){
                if( res[i][j] == -1<<30 ){
                    solve( i , j , ady[i][j] );
                }
                if( !first )
                    printf(" ");
                printf("%d" , res[i][j] );
                first = false;
            }
            printf("\n");
        }
    }

    return 0;
}
