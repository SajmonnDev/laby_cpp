#include <iostream>
#include "zderzacz.h"


int main() {
    zderzacz dane1(900, "pp", 1.5, 1402051215);
    zderzacz dane2(5500, "PbPb", 0.5, 2102031205);
    zderzacz dane3(900, "pp", 2.1, 140204315);
    zderzacz dane4(1100, "pp", 3.2, 1401051215);


    baza pp, PbPb;
    pp + dane1;
    pp + dane3;
    pp + dane4;
    std::cout << pp;

    pp.ilosc_danych();
    pp.wypisz_ilosc_baz();

    PbPb + dane2;
    std::cout << PbPb;


    pp - dane1;
    std::cout << pp;

    pp.ilosc_danych();
    pp.wypisz_ilosc_baz();
}
