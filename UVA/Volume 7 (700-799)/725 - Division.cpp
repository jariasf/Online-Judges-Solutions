/*****************************************
 ***Problema: Division
 ***ID: 725
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
#include <limits>
#include <fstream>
#include<fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
string toStr(int n){
   stringstream ss;
   ss<<n;
   string s;
   ss>>s;
   return s;
}
string llenar(string s){
    int l=s.length();
    for(int i=0;i<5-l;i++)s="0"+s;
    return s;
}

bool Dif(string n,string m){
    int a[10]={0};
    for(int i=0;i<n.length();i++){
        a[n[i]-'0']++;
    }
    for(int i=0;i<m.length();i++){
        a[m[i]-'0']++;
    }

    for(int i=0;i<10;i++){
       if(a[i]>1)return false;
    }
    return true;
}


int main(){
    int n;
    bool f=false;


    while(cin>>n && n){
        if(f)cout<<endl;
        bool b=false;

        for(int i=0;i<10;i++){

           for(int j=0;j<10;j++){
              if(i==j)continue;
              for(int k=0;k<10;k++){
                 if(k==j || k==i)continue;
                 for(int q=0;q<10;q++){
                    if(q==k || q==j || q==i)continue;
                    for(int w=0;w<10;w++){
                        if(w==q || w==k || w==j || w==i)continue;
                        int num=i*10000+j*1000+k*100+q*10+w;

                        if(num%n == 0){


                           string n1=llenar(toStr(num));
                           string n2=llenar(toStr(num/n));
                           if(!Dif(n1,n2))continue;
                           cout<<n1<<" / "<<n2<<" = "<<n<<endl;
                           b=true;
                        }
                    }
                 }
              }
           }
        }
        if(!b)cout<<"There are no solutions for "<<n<<"."<<endl;
        f=true;
    }

    return 0;
}
