#include <iostream>
#include <fstream>
using namespace std;
struct Figure{
    string stroke="none";
    double stroke_width=1;
    string fill = "none";
    string opacity;
    Figure(string stroke, double stroke_width, string fill,string opacity):stroke(stroke),stroke_width(stroke_width),fill(fill), opacity(opacity){};
};

struct Line:Figure{
    double x1;
    double y1;
    double x2;
    double y2;
    Line(double x1,double y1,double x2,double y2, string color, double stroke_size, string fill,string opacity):x1(x1), y1(y1), x2(x2),y2(y2), Figure(color,stroke_size,fill,opacity){};
};

struct Circle:Figure{
    double r;
    double cx;
    double cy;
    Circle(double r,double cx,double cy,string stroke,double stroke_size,string fill,string opacity):r(r),cx(cx),cy(cy), Figure(stroke,stroke_size, fill,opacity ) {};
};

struct PolylineTriangle:Figure{
    double point1x;
    double point1y;
    double point2x;
    double point2y;
    double point3x;
    double point3y;
    PolylineTriangle(double point1x,double point1y,double point2x,double point2y, double point3x, double point3y, string stroke,double stroke_size,string fill,string opacity):point1x(point1x),point1y(point1y),point2x(point2x),point2y(point2y),point3x(point3x),point3y(point3y), Figure(stroke,stroke_size, fill,opacity ) {};
};

struct Rect:Figure{
    double width;
    double height;
    double rx;
    double ry;
    Rect(double width,double height, double rx,double ry,string stroke,double stroke_size,string fill,string opacity ):width(width), height(height),rx(),ry(), Figure(stroke, stroke_size,fill,opacity){};
};

ofstream& operator<<(ofstream& os, const Line& l){
    os<<"<line x1=\""<<l.x1<<"\""<<" y1=\""<<l.y1<<"\""<<" x2=\""<<l.x2<<"\""<<" y2=\""<<l.y2<<"\""<< " stroke=\""<<l.stroke<<"\""<<" stroke-width=\""<<l.stroke_width<<"\""<<" opacity=\""<<l.opacity<<"\""<<" />"<<endl;
    return os;
}

ofstream& operator<<(ofstream& os, const Circle& c){
    os<<"<circle r=\""<<c.r<<"\""<<" cx=\""<<c.cx<<"\""<<" cy=\""<<c.cy<<"\""<<" stroke=\""<<c.stroke<<"\""<<" stroke-width=\""<<c.stroke_width<<"\""<<" fill=\""<<c.fill<<"\""<<" opacity=\""<<c.opacity<<"\""<<" />"<<endl;
    return os;
}

ofstream& operator<<(ofstream& os, const PolylineTriangle& p){
    os<<"<polyline points=\""<<p.point1x<<","<<p.point1y<<" "<<p.point2x<<","<<p.point2y<<" "<<p.point3x<<","<<p.point3y<<"\""<<" stroke=\""<<p.stroke<<"\""<<" stroke-width=\""<<p.stroke_width<<"\""<<" fill=\""<<p.fill<<"\""<<" opacity=\""<<p.opacity<<"\""<<" />"<<endl;
    return os;
}
ofstream& operator<<(ofstream& os, const Rect& r){
    os<<"<rect width=\""<<r.width<<"\""<<" height=\""<<r.height<<"\""<<" rx=\""<<r.rx<<"\""<<" ry=\""<<r.ry<<"\""<<" stroke=\""<<r.stroke<<"\""<<" stroke-width=\""<<r.stroke_width<<"\""<<" fill=\""<<r.fill<<"\""<<" opacity=\""<<r.opacity<<"\""<<" />"<<endl;
    return os;

}
int main(){
    ofstream os("img.svg");
    os<<"<svg  viewBox=\"0 0 250 150\">"<<endl;
    Circle c(10,100,40,"none",2,"blue","100%");
    Rect r(250,150,0,0,"none",0,"#F5F0DC","100%");
    os<<r;
    Circle c1(30,30,30,"none",0,"pink","100%");
   os<<c1;
   c1=Circle(20,30,30,"none",0,"grey","100%");
    os<<c1;
    c1=Circle(10,30,30,"none",0,"purple","100%");
    os<<c1;
    c1=Circle(10,50,64,"none",0,"brown","100%");
    os<<c1;
   PolylineTriangle p(125,97,150,10,175,100,"black",1,"white","100%");
    os<<p;
    p = PolylineTriangle(50,90,85,50,150,100,"black",1,"aqua","30%");
    os<<p;
    Line l (150,10,117,125,"black",1,"none", "100%");
    os<<l;
    l = Line (150,10,182,125,"black",1,"none", "100%");
    os<<l;
    l = Line  (75,115,200,115,"black",1,"none", "100%");
    os<<l;
    p=PolylineTriangle(123,93,173,70,190,93,"none",1,"yellow","70%");
    os<<p;
    c1=Circle(7,167,82,"none",0,"purple","100%");
    os<<c1;
    c1=Circle(6,167,82,"none",0,"blue","100%");
    os<<c1;
    c1=Circle(5,167,82,"none",0,"orange","100%");
    os<<c1;
    c1=Circle(4,167,82,"none",0,"white","100%");
    os<<c1;

    os<<"</svg>";



    return 0;
}

