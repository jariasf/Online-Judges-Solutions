/*****************************************
 ***Problema: Mirror, Mirror
 ***ID: 466
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
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
#include<fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 12
char ini[MAX][MAX];
char fin[MAX][MAX];
int n;
char aux[MAX][MAX];
char cini[MAX][MAX];

bool iguales(){
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(ini[i][j]!=fin[i][j])return false;
       }
    }
    return true;
}


void rotar(){
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           aux[j][n-i-1]=ini[i][j];
       }
    }

    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           ini[i][j]=aux[i][j];
       }
    }

}

void Reflex(){

    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           aux[ n - j - 1 ][ i ] = ini[ j ][ i ];
       }
    }

    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           ini[i][j]=aux[i][j];
       }
    }
}


int main(){
    int q = 1;
    while( cin>>n ){
        for(int i=0;i<n;i++)cin>>ini[i]>>fin[ i ];
        cout<<"Pattern " <<q++<<" was ";
        if(iguales()){cout<<"preserved."<<endl; continue;}
        ///rotamos 90 grados
        rotar();
        if(iguales()){cout<<"rotated 90 degrees."<<endl;continue;}
        ///rotamos 180 grados
        rotar();
        if(iguales()){cout<<"rotated 180 degrees."<<endl;continue;}
        ///rotamos 270 grados
        rotar();
        if(iguales()){cout<<"rotated 270 degrees."<<endl;continue;}
        ///reflexion
        rotar();
        Reflex();
        if(iguales()){cout<<"reflected vertically."<<endl;continue;}
        ///combinacion
        rotar();if(iguales()){cout<<"reflected vertically and rotated 90 degrees."<<endl; continue;}
        rotar();if(iguales()){cout<<"reflected vertically and rotated 180 degrees."<<endl;continue;}
        rotar();if(iguales()){cout<<"reflected vertically and rotated 270 degrees."<<endl; continue;}
        ///nada
        rotar();if(iguales()){cout<<"preserved"<<endl; continue;}
        ///invalido
        cout<<"improperly transformed."<<endl;
    }
    return 0;
}
