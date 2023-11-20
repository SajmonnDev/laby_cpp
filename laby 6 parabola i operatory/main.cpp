//
// Created by szymon on 20.11.2023.
//
#include <iostream>
#include "parabola.h"

int main(){

    std::cout << "Podaj wartosci 3 puntow: ";
    double x,y;
    std::cin >> x >> y;
    point p1 = point(x,y);
    p1.show();
    std::cin >> x >> y;
    point p2 = point(x,y);
    p2.show();
    std::cin >> x >> y;
    point p3 = point(x,y);
    p3.show();
    parabola para = parabola(p1, p2, p3);
    para.oblicz_wspolczynniki();
    para.show();
    std::string check = para.check(p1,p2,p3);
    std::cout << check << std::endl;

    std::cout << "Podaj punkt badania pochodnej: ";
    point poch = point(x,y);
    std::cin >> x >> y;
    para.pochodna(x,y);
    p1 == p2;
    return 0;
}

