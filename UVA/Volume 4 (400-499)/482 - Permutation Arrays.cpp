/*****************************************
 ***Problema: Permutation Arrays
 ***ID: 482
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>

#define N 1001

using namespace std;

int pos[N];
string array[N];

int main(){
    int num_of_cases, n, temp;

    cin>>num_of_cases;
    for(int counter=0; counter<num_of_cases; counter++)    {
        if(counter!=0)
            cout<<endl;
        n=0;

        do{
            cin>>temp;
            pos[temp-1]=n++;
        }
        while(getchar()!='\n');

        for(int i=0;i<n;i++)
            cin>>array[i];

        for(int i=0;i<n;i++)
            cout<<array[pos[i]]<<endl;
    }

    return 0;
}

