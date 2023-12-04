
#include "zderzacz.h"
#include <iostream>


int baza::ilosc_baz = 0;

baza& baza::operator+(const zderzacz &dane) {
    int len = baza_zderzacza.size();
    if(len < 2){
        this -> baza_zderzacza.push_back(dane);
    }
    else{
        std::cout << "Nie mozna dodac danych do bazy, osiagnieto limit." << std::endl;
    }
    return *this;
}

baza& baza::operator-(const zderzacz &dane) {
    int len = baza_zderzacza.size();
    for(int i = 0; i < len; i++){
        if(baza_zderzacza[i] == dane){
            baza_zderzacza.erase(baza_zderzacza.begin() + i);
        }
    }
    return *this;
}

std::ostream& operator<< (std::ostream& os, const baza& base){
    int len = base.baza_zderzacza.size();
    os << "---------------BAZA DANYCH-----------------" << std::endl;
    for(int i = 0; i < len; i++){
        os << i + 1 << "." << std::endl;
        os << base.baza_zderzacza[i];
        os << std::endl;
    }
    os << "-----------------------------------" << std::endl;
    return os;
}


std::ostream &operator<<(std::ostream &os, const zderzacz &zderz) {
    os << "Energia: " << zderz.energia << std::endl << "Typ: " << zderz.typ << std::endl << "Ilosc zderzen w mln: " << zderz.ilosc_zderzen << std::endl << "Data: " << zderz.data << std::endl;
    return os;
}

void baza::ilosc_danych() {
    int len = baza_zderzacza.size();
    std::cout << "Pamieci potrzeba: " << len*4 << std::endl;
}

baza::baza() {
    ilosc_baz += 1;
}

baza::~baza(){
    ilosc_baz -= 1;
}

void baza::wypisz_ilosc_baz() {
    std::cout << "Ilosc baz danych: " << ilosc_baz << std::endl;
}

