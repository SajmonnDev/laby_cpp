#include <iostream>

#ifndef __PARABOLA__
#define __PARABOLA__

class point {
    double *x, *y;
    static int counter;

public:
    point(double X, double Y);
    point(const point &p);
    ~point();
    double policz_y(double a, double b, double c) const;
    bool operator==(const point &p) const;
    friend std::ostream& operator<<(std::ostream& os, const point& p);

    static void wypisz_pkt();
    double getX() const { return *x; }
    double getY() const { return *y; }
    friend class parabola;
};

class parabola {
    double *a, *b, *c;
    static int licz_parabol;

public:
    parabola(point P1, point P2, point P3);
    parabola(const parabola &para);
    ~parabola();
    bool operator==(const parabola &para) const;
    friend std::ostream& operator<<(std::ostream& os, const parabola& para);

    void oblicz_wspolczynniki(point P1, point P2, point P3);
    static void pokaz_licz_parabol();
    void pochodna(double x_0) const;
    std::string check(const point& P1, const point& P2, const point& P3) const;

    double getA() const { return *a; }
    double getB() const { return *b; }
    double getC() const { return *c; }
};

#endif // __PARABOLA__
