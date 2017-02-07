/****************************************************
 ***Problema: Point in Figures Rectangles and Circles
 ***ID: 477
 ***Juez: UVA
 ***Tipo: Geometry, point in rectangle adn circle.
 ***Autor: Jhosimar George Arias Figueroa
 ****************************************************/

#include<iostream>
#include<stdio.h>
#include<vector>
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

///Distancia entre dos puntos
double dist(Point p1,Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

struct Figure{
    int pos;
    double radio;
    Figure(int p,double r):pos(p),radio(r){}
    Figure(){}
};
int main(){
    double x1,y1,x2,y2,xx,yy,xc,yc,radio;
    char c[2];
    vector<pair<Rectangle,int> > v;
    vector<pair<Point,Figure> > circle;
    int pos=1;
    while(scanf("%s",&c) ){
        if(c[0]=='*')break;
        if(c[0]=='r'){
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            Point A(x1,y2),B(x2,y1);
            Rectangle R(A,B);
            v.push_back(make_pair(R,pos++));
        }
        else if(c[0]=='c'){
            scanf("%lf %lf %lf",&xc,&yc,&radio);
            Point A(xc,yc);
            Figure F(pos++,radio);
            circle.push_back(make_pair(A,F));

        }
    }
    int cont=1;

    while(scanf("%lf %lf",&xx,&yy) && (xx!=9999.9 && yy!=9999.9)){
        bool b=false;
        Point P(xx,yy);
        for(int i=0;i<v.size();i++){

           if(insideRect(P,v[i].first.leftT,v[i].first.rightD)){
             printf("Point %d is contained in figure %d\n",cont,v[i].second);//(i+1));
             b=true;
           }
        }
        for(int i=0;i<circle.size();i++){
           Point B(circle[i].first.x,circle[i].first.y);
           if(sqrt(dist(P,B))<circle[i].second.radio){
             printf("Point %d is contained in figure %d\n",cont,circle[i].second.pos);
             b=true;
           }
        }
        if(!b)printf("Point %d is not contained in any figure\n",cont);
        cont++;
    }

    return 0;
}
