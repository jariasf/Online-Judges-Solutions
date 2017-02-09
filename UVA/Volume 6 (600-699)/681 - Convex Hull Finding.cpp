/*****************************************
 ***Problema: Convex Hull Finding
 ***ID: 681
 ***Juez: UVA
 ***Tipo: Geometry, Convex Hull
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <algorithm>
#include <vector>
#include<iostream>
using namespace std;

struct Point{
   Point(int x1,int y1){
       x=x1;
       y=y1;
   }
   Point(){

   }
   int x;
   int y;
   ///PRODUCTO PUNTO
   int operator *(const Point &p1)const{
       return x*p1.x+y*p1.y;
   }
   ///PRODUCTO CRUZ
   int operator ^(const Point &p1)const{
       return x*p1.y-y*p1.x;
   }
   Point operator-(const Point &p1)const{
       Point a(x-p1.x,y-p1.y);
       return a;
   }

   bool operator<(const Point &p1) const{
       return (y<p1.y || (y==p1.y && x<p1.x));
   }

};


///Direccion de vectores
///1 Sentido Antihorario
///-1 Sentido Horario
///Puntos Colineales(si todos los puntos forman una recta)
int ccw(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}


///CONVER HULL CON ALGORITMO MONOTONE CHAIN
///ORDENA PUNTOS Y RECORRE PARTE SUPERIOR EH INFERIOR
vector<Point> monotoneChain(vector<Point> P){
    int n=P.size(),k=0;
    vector<Point> H(2*n);

    //Ordenamos los puntos lexicograficamente
    sort(P.begin(),P.end());

    //Construimos convex hull limite inferior
    for(int i=0;i<n;i++){
        while(k>=2 && ccw(H[k-2],H[k-1],P[i])<=0)k--;
        H[k++]=P[i];
    }
    //Construimos convex hull limite superior
    for(int i=n-2, t=k+1;i>=0;i--){
        while(k>=t && ccw(H[k-2],H[k-1],P[i])<=0)k--;
        H[k++]=P[i];
    }
    H.resize(k);
    return H;
}

int main(){

   int casos,puntos,x,y;
   cin>>casos;
   cout<<casos<<endl;
   while(casos--){
      cin>>puntos;

      vector<Point> v;
      for(int i=0;i<puntos;i++){
        cin>>x>>y;
        Point p(x,y);
        v.push_back(p);
      }
      if(casos)cin>>puntos;
      vector<Point> pp=monotoneChain(v);
      cout<<pp.size()<<endl;
      for(int i=0;i<pp.size();i++){
         cout<<pp[i].x<<" "<<pp[i].y<<endl;
      }
      if(casos)cout<<-1<<endl;
   }
   return 0;
}
