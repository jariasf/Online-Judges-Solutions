/*****************************************
 ***Problema: Beggar My Neighbour
 ***ID: 162
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;

int main() {
    string tmp;
    while(cin >> tmp, tmp[ 0 ] != '#') {
        deque<string> A[ 2 ];
        A[ 0 ].push_front(tmp);
        for( int i = 1 ; i < 52 ; ++i ) {
            cin >> tmp;
            A[ i % 2 ].push_front( tmp );
        }
        deque<string> T;
        int turn = 0, needed = 1, last = 0;
        bool flag = 1;
        while( flag ) {
            while( needed-- ) {
                if( !A[ turn ].size()) {
                    printf("%d%3d\n", ( turn ? 2 : 1 ), A[ ( turn + 1 ) % 2 ].size());
                    flag= 0;
                    break;
                }
                T.push_back( A[ turn ].front() );
                A[ turn ].pop_front();
                int tn = needed;
                switch( T.back()[ 1 ] ) {
                    case 'A':
                        ++needed;
                    case 'K':
                        ++needed;
                    case 'Q':
                        ++needed;
                    case 'J':
                        ++needed;
                        needed -= tn;
                        last = turn + 1;
                        turn = ( turn + 1 )%2;
                }

            }
            if(flag) {
                if(last--) {
                    A[ last ].insert( A[ last ].end(), T.begin(), T.end());
                    T.clear();
                    turn = ( last + 1 ) % 2;
                }
                last = 0;
                needed = 1;
                turn = ( turn + 1 ) % 2;
            }
        }
    }
    return 0;
}
