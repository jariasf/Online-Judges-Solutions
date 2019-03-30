/*****************************************
 ***Problema: Broken Keyboard
 ***ID: 11988
 ***Juez: UVA
 ***Tipo: String ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<deque>
using namespace std;

deque<string> deq;

void insert( bool pos , string &s );

int main(){
    string tmp;
    bool end = true;
    char c;
    while( c = getchar() ){
        if( c == EOF ) return 0;
        if( c == '\n' ) {
            insert( end , tmp );
            while( deq.size() ){
                tmp = deq.front();
                cout<<tmp;
                deq.pop_front();
            }
            cout<<endl;
            deq.clear();
            tmp = "";
            end= true;
        }
        else if( c == '[' ){
            if(tmp != "")
                insert( end , tmp );
            end = false;
        }
        else if( c == ']' ) {
            if(tmp != "")
                insert( end , tmp );
            end = true;
        }
        else tmp.push_back( c );
    }
    return 0;
}

void insert(bool pos,string & s){
    if(pos)    deq.push_back(s);
    else deq.push_front(s);
    s="";
}
