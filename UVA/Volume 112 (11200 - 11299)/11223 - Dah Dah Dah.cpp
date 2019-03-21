/*****************************************
 ***Problema: Dah Dah Dah
 ***ID: 11223
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


char Solve( string s ){
	if( s == ".-" )  return 'A';
	if( s == "-..." ) return 'B';
	if( s == "-.-." ) return 'C';
	if( s == "-.." ) return 'D';
	if( s == "." )	return 'E';
	if( s == "..-." ) return 'F';
	if( s == "--." ) return 'G';
	if( s == "...." ) return 'H';
	if( s == ".." )	return 'I';
	if( s == ".---" ) return 'J';
	if( s == "-.-" ) return 'K';
	if( s == ".-.." ) return 'L';
    if( s == "..." ) return 'S';
    if( s == "-"  )	 return 'T';
    if( s == "..-" ) return 'U';
    if( s == ".----" ) return '1';
    if( s == "..---" ) return '2';
    if( s == "...--" ) return '3';
    if( s == "--..--" ) return ',';
    if( s == "..--.." ) return '?';
    if( s == "-.-.-." ) return ';';
    if( s == "-...-" ) return '=';
    if( s == ".-.-.-" ) return '.';
    if( s == "---..." ) return ':';
	if( s == "--" ) return 'M';
	if( s == "-." ) return 'N';
	if( s == ".--" ) return 'W';
	if( s == "....." ) return '5';
	if( s == "-.-.--" ) return '!';
	if( s == "-....-" ) return '-';
	if( s == "---" ) return 'O';
	if( s == "-..-" ) return 'X';
	if( s == "-...." ) return '6';
	if( s == "-..-." ) return '/';
	if( s == ".--." ) return 'P';
	if( s == "..--.-" ) return '_';
	if( s == "-.--" ) return 'Y';
	if( s == "--..." ) return '7';
	if( s == "-.--." ) return '(';
	if( s == ".-..-." ) return '\"';
	if( s == "--.-" ) return 'Q';
	if( s == "--.." ) return 'Z';
	if( s == "---.." ) return '8';
	if( s == "-.--.-" ) return ')';
	if( s == ".--.-." ) return '@';
	if( s == ".-." ) return 'R';
	if( s == "-----" ) return '0';
	if( s == "----." ) return '9';
	if( s == ".-..." ) return '&';
	if( s == "...-" ) return 'V';
    if( s == "....-" ) return '4';
    if( s == ".----." ) return '\'';
    if( s == ".-.-." ) return '+';

}

#define MAX 2005
int main(){

    int t, l , e;
    cin>>t;
    string s, aux;
    cin.get();
    for( int q = 1; q <= t; ++q ){
        if( q - 1)putchar('\n');
        getline( cin , s );
        e = 0;
        s+=" ";
        l = s.length();
        cout<<"Message #"<<q<<endl;
        for( int i = 0 ; i < l ; ++i ){
            if( s[i] == ' ') {
                e++;
                if ( e == 1 ){
                    putchar( Solve(aux) );
                }
                if( e == 2 && i != l -1)putchar(' ');
                aux = "";
            }
            else { aux += s[i]; e = 0; }
        }
        putchar('\n');
    }

    return 0;
}
