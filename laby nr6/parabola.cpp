#include "parabola.h"
#include <iostream>
#include <cmath>

int point::counter = 0;
int parabola::licz_parabol = 0;

point::point(double X, double Y) : x(new double(X)), y(new double(Y)) { counter++; }
point::point(const point &p) : x(new double(*p.x)), y(new double(*p.y)) { counter++; }
point::~point() { delete x; delete y; counter--; }


bool point::operator==(const point &p) const {
    return *x == *p.x && *y == *p.y;
}

std::ostream& operator<<(std::ostream& os, const point& p) {
    os << "[" << *p.x << ", " << *p.y << "]";
    return os;
}

void point::wypisz_pkt() {
    std::cout << "Liczba punktow to: " << counter << std::endl;
}

parabola::parabola(point P1, point P2, point P3) : a(new double(0)), b(new double(0)), c(new double(0)) {
    oblicz_wspolczynniki(P1, P2, P3);
    licz_parabol++;
}

double point::policz_y(double a, double b, double c) const {
    return a * (*x) * (*x) + b * (*x) + c;
}

parabola::parabola(const parabola &para) : a(new double(*para.a)), b(new double(*para.b)), c(new double(*para.c)) { licz_parabol++; }

parabola::~parabola() { delete a; delete b; delete c; licz_parabol--; }


bool parabola::operator==(const parabola &para) const {
    return *a == *para.a && *b == *para.b && *c == *para.c;
}

std::ostream& operator<<(std::ostream& os, const parabola& para) {
    os << "y = " << *para.a << "x^2 + " << *para.b << "x + " << *para.c;
    return os;
}

std::string parabola::check(const point& P1, const point& P2, const point& P3) const {
    double y1 = P1.policz_y(*a, *b, *c);
    double y2 = P2.policz_y(*a, *b, *c);
    double y3 = P3.policz_y(*a, *b, *c);

    if ((y1 - P1.getY()) == 0 && (y2 - P2.getY()) == 0 && (y3 - P3.getY()) == 0) {
        return "Te 3 punkty leżą na paraboli.";
    } else {
        return "Te 3 punkty nie leżą na paraboli.";
    }
}

void parabola::oblicz_wspolczynniki(point P1, point P2, point P3) {
    double x1 = *P1.x, y1 = *P1.y;
    double x2 = *P2.x, y2 = *P2.y;
    double x3 = *P3.x, y3 = *P3.y;

    double denom = (x1 - x2) * (x1 - x3) * (x2 - x3);


    *a = ((x3 * (y2 - y1) + x2 * (y1 - y3) + x1 * (y3 - y2)) / denom);
    *b = ((x3*x3 * (y1 - y2) + x2*x2 * (y3 - y1) + x1*x1 * (y2 - y3)) / denom);
    *c = ((x2 * x3 * (x2 - x3) * y1 + x3 * x1 * (x3 - x1) * y2 + x1 * x2 * (x1 - x2) * y3) / denom);
}

void parabola::pokaz_licz_parabol() {
    std::cout << "Ilosc parabol: " << licz_parabol << std::endl;
}

void parabola::pochodna(double x_0) const {
    double poch = 2 * *a * x_0 + *b;
    double a_pochodnej = 2 * *a * x_0 + *b; // f'(x_0)
    double b_pochodnej = pow(*a * (x_0),2) + *b * x_0 + *c - (2 * *a * x_0 + *b)*x_0; // f(x_0) - f'(x_0)*x_0
    std::cout << "Pochodna paraboli w punkcie x = " << x_0 << " wynosi: y = " << a_pochodnej <<"x^2 + " << b_pochodnej << " i ma wartosc: " << poch << std::endl;
}
