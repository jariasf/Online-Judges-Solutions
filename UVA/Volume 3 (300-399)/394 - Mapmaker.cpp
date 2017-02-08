/*****************************************
 ***Problema: Mapmaker
 ***ID: 394
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
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
#include<fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct Estado{

    int B;
    int D;
    int CD;
    vector<int> U;
    vector<int> L;
    Estado(){};

};

int main(){

    int n, m , B, D, L, U, resp,CD;
    string s;
    map< string , Estado > mp;
    cin>>n>>m;
    while( n-- ){
        cin>>s>>B>>CD>>D;
        Estado nuevo;
        nuevo.B = B;
        nuevo.D = D;
        nuevo.CD = CD;
        nuevo.U.push_back(0);
        nuevo.L.push_back(0);
        while( D-- ){
            cin>>L>>U;
            //vector de pares
            nuevo.U.push_back(U);
            nuevo.L.push_back(L);
        }
        mp[s]=nuevo;
    }

    while( m-- ){
        cin>>s;
        Estado actual = mp[s];

        int i [ actual.B ], C[ actual.D + 1 ];

        for(int j = 1 ; j <= actual.D ; ++j ){
            cin>>i[j];
        }

        //SOLUCION
        //Cd
        C[ actual.D ] = actual.CD;

        for( int j = actual.D - 1 ; j >= 1 ; --j ){
            C[j] = C[j+1]* ( actual.U[j+1] - actual.L[j+1]  + 1);
        }

        C[0] = actual.B;

        for ( int j = 1 ; j <= actual.D ; ++j ){
            C[0]-=(C[j]*actual.L[j]);

        }

        resp = C[0];

        for( int j = 1;j <=actual.D ; ++j){
           resp+= C[j]*i[j];
        }


        //IMPRESION DE RESPUESTA
        cout<<s<<"["<<i[1];
        for(int j = 2 ; j <= actual.D; ++j ){
            cout<<", "<<i[j];
        }
        cout<<"] = "<<resp<<endl;
    }


    return 0;
}
