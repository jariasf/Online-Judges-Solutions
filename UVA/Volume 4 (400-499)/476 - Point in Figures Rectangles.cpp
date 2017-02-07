/*****************************************
 ***Problema: Point in Figures Rectangles
 ***ID: 476
 ***Juez: UVA
 ***Tipo: Geometry, point in rectangle.
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
#define EPS 1e-9
struct Point{
   Point(double x1,double y1){
       x=x1;
       y=y1;
   }
   Point(){

   }
   double x;
   double y;
   ///PRODUCTO PUNTO
   double operator *(const Point &p1)const{
       return x*p1.x+y*p1.y;
   }
   ///PRODUCTO CRUZ
   double operator ^(const Point &p1)const{
       return x*p1.y-y*p1.x;
   }
   Point operator-(const Point &p1)const{
       Point a(x-p1.x,y-p1.y);
       return a;
   }

};

struct Rectangle{
    Rectangle(Point ll,Point rr):leftT(ll),rightD(rr){}
    Rectangle(Point lt,Point ld,Point rt,Point rd):leftT(lt),rightD(rd),leftD(ld),rightT(rt){}
    Point leftD;
    Point rightT;
    Point leftT;
    Point rightD;

};

///SI ESTA DENTRO DE RECTANGULO
///p: Punto averiguar si esta dentro de rectangulo
///L: botton-left de rectangulo
///R: top-right de rectangulo
bool insideRect(Point p,Point L, Point R){
    if(p.x<R.x && L.x<p.x && p.y<R.y && L.y<p.y){
       return true;
    }
    return false;
}
int main(){
    double x1,y1,x2,y2,xx,yy;
    char c[2];
    vector<Rectangle> v;
    while(scanf("%s",&c) ){
        if(c[0]=='*')break;
        scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
        Point A(x1,y2),B(x2,y1);
        Rectangle R(A,B);
        v.push_back(R);
    }
    int cont=1;

    while(scanf("%lf %lf",&xx,&yy) && (xx!=9999.9 && yy!=9999.9)){
        bool b=false;
        Point P(xx,yy);
        for(int i=0;i<v.size();i++){
           if(insideRect(P,v[i].leftT,v[i].rightD)){
             printf("Point %d is contained in figure %d\n",cont,(i+1));
             b=true;
           }
        }
        if(!b)printf("Point %d is not contained in any figure\n",cont);
        cont++;
    }

    return 0;
}
