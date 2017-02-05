/*****************************************
 ***Problema: Intersecting Lines
 ***ID: 378
 ***Juez: UVA
 ***Tipo: Geometry, Lines.
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
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
   bool operator =(const Point &p1)const{
       return (x==p1.x && y==p1.y );
   }
};

void line_line_intersection(Point A,Point B,Point C,Point D){
  Point CD=C-D, CA=A-C,AB=B-A,AC=A-C;
  double t0=CD^CA;
  double t1=AB^AC;
  double det=AB^CD;

  if (fabs(det) < EPS){
    //paralelos
    if (fabs(t0) < EPS || fabs(t1) < EPS){
      //misma linea
      printf("LINE\n");
    }else{
      //paralelas
      printf("NONE\n");
    }
  }else{
    t0 /= det;
    t1 /= det;
    double x = A.x + t0*(B.x-A.x);
    double y = A.y + t0*(B.y-A.y);
    //interseccion de puntos (x, y)
    printf("POINT %.2lf %.2lf\n", x, y);
  }
}

int main(){
    int casos;
    double x1,y1,x2,y2,x3,y3,x4,y4;
    bool first=true;
    scanf("%d",&casos);
    printf("INTERSECTING LINES OUTPUT\n");
    while(casos--){
       scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
       Point p1(x1,y1),p2(x2,y2);
       Point p3(x3,y3),p4(x4,y4);
       line_line_intersection(p1,p2,p3,p4);
    }
    printf("END OF OUTPUT\n");

    return 0;
}

