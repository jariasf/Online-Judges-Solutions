/*****************************************
 ***Problema: Tic Tac Toe
 ***ID: 10363
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <iostream>
using namespace std;
char map[4][4];

bool vict(char c){
    //filas
    for(int i = 0; i < 3; i++)
       for(int j = 0; j < 3; j++){
        if( map[i][j] != c ) break;
        if( j == 2 ) return 1;
       }

    //columnas
    for(int i = 0; i < 3; i++)
       for(int j = 0; j < 3; j++){
        if( map[j][i] != c ) break;
        if( j == 2 ) return 1;
       }

    //diagonal derecha
    for( int i = 0 ; i < 3 ; i++){
       if( map[i][i] != c ) break;
       if( i == 2 ) return 1;
    }

    //diagonal izquierda
    for(int i = 0 ; i < 3 ; i++){
       if( map[i][2-i] != c ) break;
       if( i == 2 ) return 1;
    }
    return 0;
}

bool check(){
    int no, nx, nf;
    no = nx = nf = 0;

    for(int i=0; i<3; i++)
       for(int j=0; j<3; j++)
        if(map[i][j] == 'O') no++;
        else if(map[i][j] == 'X') nx++;
        else nf++;

    if( nx < no || nx > no + 1 ) return 0;
    if( vict('O') && nx > no ) return 0;
    if( vict('X') && no == nx ) return 0;
    if( !nf || vict('O') || vict('X') ) return 1;
    return 1;
}

int main(){
    int t;
    cin >> t;
    while( t-- ){
       for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
         cin >> map[i][j];

       if( check() ) cout << "yes\n";
       else cout << "no\n";
    }
    return 0;
}
