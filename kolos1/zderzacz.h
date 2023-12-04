

#ifndef KOLOS1_ZDERZACZ_H
#define KOLOS1_ZDERZACZ_H

#include <iostream>
#include <vector>

class zderzacz{

    unsigned int energia;
    std::string typ;
    double ilosc_zderzen;
    long data;

public:
    zderzacz(unsigned int E, std::string t, double zderzen, long d) : energia(E), typ(t), ilosc_zderzen(zderzen), data(d) {}
    friend class baza;
    ~zderzacz(){};
    bool operator==(const zderzacz& other){
        return energia == other.energia && typ == other.typ &&
               ilosc_zderzen == other.ilosc_zderzen && data == other.data;
    }


    friend std::ostream& operator<<(std::ostream& os, const zderzacz& zderz);
};

class baza{
    static int ilosc_baz;
    std::vector<zderzacz> baza_zderzacza;
public:
    baza();
    ~baza();
    void wypisz_ilosc_baz();
    baza& operator+ (const zderzacz& dane);
    baza& operator- (const zderzacz& dane);
    friend std::ostream& operator<<(std::ostream& os, const baza& base);
    void ilosc_danych();

};

std::ostream& operator<<(std::ostream& os, const baza& base);
std::ostream& operator<<(std::ostream& os, const zderzacz& zderz);
#endif //KOLOS1_ZDERZACZ_H
