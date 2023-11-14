//
// Created by szymon on 11.11.2023.
//
#include <iostream>

#ifndef __PARABOLA__
#define __PARABOLA__

class point{

    double x,y;
    int counter = 0;

public:
    point(double X, double Y);
    ~point();
    void show();
    double policz_y(double a, double b, double c, double x);
    void wypisz_pkt();
    friend class parabola;
};

class parabola{
    double a,b,c;
    point p1, p2, p3;
    int licz_parabol = 0;

public:
    parabola(point P1, point P2, point P3);
    ~parabola();
    void oblicz_wspolczynniki();
    void pokaz_licz_parabol();
    void show();
    std::string check(point p1, point p2, point p3);
    friend class point;
};


#endif

