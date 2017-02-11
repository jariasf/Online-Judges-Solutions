/*****************************************
 ***Problema: Substitution Cipher
 ***ID: 865
 ***Juez: UVA
 ***Tipo: Ad hoc, String manipulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    string s;
    string abc,rabc;
    int t , i , l;
    cin>>t;
    getline( cin , s );
    cin.get();
    bool b = false;
    while(t-- ){
        if( b )cout<<endl;
        b=true;

        getline(cin,abc);
        getline(cin,rabc);
        cout<<rabc<<endl<<abc<<endl;

        while( getline( cin , s ) && s[0] !='\0'){
            l = s.size();
            string s2 = "";
            for( i = 0 ; i < l ; i++ ){
               int t = abc.find( s[ i ] );
               if( t != string::npos ){
                  s2 += rabc[ (int) t];
               }
               else s2 += s[ i ];
            }
            cout<<s2<<endl;
        }
    }
    return 0;
}
