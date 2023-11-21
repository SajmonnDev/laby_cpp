#include <iostream>
#include "parabola.h"

int main() {
    double x, y;

    std::cout << "Podaj wartosci dla punktu 1: ";
    std::cin >> x >> y;
    point p1(x, y);

    std::cout << "Podaj wartosci dla punktu 2: ";
    std::cin >> x >> y;
    point p2(x, y);

    std::cout << "Podaj wartosci dla punktu 3: ";
    std::cin >> x >> y;
    point p3(x, y);

    parabola para(p1, p2, p3);

    std::cout << "Parabola stworzona z punktow: " << p1 << ", " << p2 << ", " << p3 << std::endl;
    std::cout << para << std::endl;

    std::cout << para.check(p1, p2, p3) << std::endl;

    std::cout << "Podaj punkt x dla obliczenia pochodnej paraboli: ";
    std::cin >> x;
    para.pochodna(x);

    return 0;
}