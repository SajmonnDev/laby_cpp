#include <iostream>
#include "macierz.h"

int main() {
    int n,m;
    float l;
    std::cout << "Podaj wymiary pierwszej macierzy oraz liczbe ktora mamy go wypelnic n m l:";
    std::cin >> n >> m >> l;
    Macierz m1 = Macierz(n, m, l);
    std::cout << "Macierz pierwsza:" << std::endl << m1 << std::endl;
    std::cout << "Podaj wymiary drugiej macierzy oraz liczbe ktora mamy go wypelnic n m l:";
    std::cin >> n >> m >> l;
    Macierz m2 = Macierz(n, m, l);
    std::cout << "Macierz druga:" << std::endl << m2 << std::endl;

    Macierz m3 = m1 + m2;
    std::cout << "Dodawanie macierzy m1 do m2:" << std::endl << m3 << std::endl;
    Macierz m4 = m1 - m2;
    std::cout << "Odejmowanie macierzy m1 do m2:" << std::endl << m4 << std::endl;
    Macierz m5 = m1 * m2;
    std::cout << "Mnozenie macierzy m1 do m2:" << std::endl << m5 << std::endl;
    return 0;
}
