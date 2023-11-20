//
// Created by szymon on 11.11.2023.
//
#include <iostream>
#include "parabola.h"
#include <math.h>

point::point(double X = 0, double Y = 0)
        : x(X), y(Y), counter(counter+1) {}

point::~point() = default;

void point::show(){
    std::cout << "[" << x << "," << y << "]" << std::endl;
}

double point::policz_y(double a, double b, double c, double x){
    return a*x*x + b*x + c;
}

void point::wypisz_pkt(){
    std::cout << "Liczba punktow to: " << counter << std::endl;
}

parabola::parabola(point P1, point P2, point P3)
        : p1(P1), p2(P2), p3(P3), licz_parabol(licz_parabol + 1) {}

parabola::~parabola() = default;

void parabola::oblicz_wspolczynniki(){
    double denom = (p1.x-p2.x) * (p1.x-p3.x) * (p2.x-p3.x);
    a     = (p3.x * (p2.y-p1.y) + p2.x * (p1.y-p3.y) + p1.x * (p3.y-p2.y)) / denom;
    b     = (pow(p3.x, 2) * (p1.y-p2.y) + pow(p2.x, 2) * (p3.y-p1.y) + pow(p1.x,2) * (p2.y-p3.y)) / denom;
    c     = (p2.x * p3.x * (p2.x-p3.x) * p1.y+p3.x * p1.x * (p3.x-p1.x) * p2.y+p1.x * p2.x * (p2.x-p2.x) * p3.y) / denom;
}

void parabola::pokaz_licz_parabol(){
    std::cout << "Ilosc parabol" << licz_parabol << std::endl;
}

std::string parabola::check(point p1, point p2, point p3){
    double y1 = p1.policz_y(a,b,c,p1.x);
    double y2 = p2.policz_y(a,b,c,p2.x);
    double y3 = p3.policz_y(a,b,c,p3.x);
    if(y1 != p1.y || y2 != p2.y || y3 != p3.y){
        return "te 3 punkty nie leza na paraboli";
    }
    else{
        return "te 3 punkty leza na paraboli";
    }
}

void parabola::show() {
    //std::cout << "a,b,c = " << a << ", " << b << ", " << c << std::endl;
    std::cout << "y = " << a << "x^2 + " << b << "x + " << c << std::endl;
}

void parabola::pochodna(double x_0){
    double a_pochodnej = 2*a*x_0 + b; // f'(x_0)
    double b_pochodnej = pow(a*(x_0),2) + b*x_0 + c - (2*a*x_0 + b)*x_0; // f(x_0) - f'(x_0)*x_0
    std::cout << "Pochodna dana jest wzorem: y = " << a_pochodnej << "x + " << b_pochodnej << std::endl;
}
