/*****************************************
 ***Problema: Pesly Palindromes
 ***ID: 353
 ***Juez: UVA
 ***Tipo: Ad hoc, String matching
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <iostream>
#include <map>
using namespace std;

bool isPalindrome(string c){
    int l = c.length();
    for(int i=0,j=l-1;i<=l/2 && j>=l/2;i++,j--){
        if(c[i]!=c[j])return false;
    }
    return true;
}

string substring( string s , int ini , int fin ){
    string ss="";
    for( int i = ini; i<= fin ; ++i ){
        ss+=s[i];
    }
    return ss;
}

int main(){
    string s , sub;
    int l, cont;

    while( cin>>s ){
        map<string ,bool > mp;
        l = s.length();
        cont = 0;
        for( int i = 0 ; i < l ; ++i){
           for( int j = i ; j < l ; ++j ){
               sub = substring(s , i , j);
               if( sub.length() > 0 && !mp[ sub ] && isPalindrome( sub ) ){ mp[ sub] = true; cont++;}
           }
        }
        cout<<"The string '"<<s<<"' contains "<<cont<<" palindromes."<<endl;
    }


    return 0;
}
