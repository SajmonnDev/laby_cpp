//
// Created by szymon on 22.11.2023.
//

#include <iostream>

#ifndef LABY_7_MACIERZE_MACIERZ_H
#define LABY_7_MACIERZE_MACIERZ_H

#define N1 = 3
#define M1 = 4
#define N2 = 3
#define M2 = 4

class Macierz{

    float **mac;
    int n,m;

public:
    Macierz(int n, int m, float l);
    Macierz();
    ~Macierz(){
        for(int i = 0; i < n; i++){
            delete[] mac[i];
        }
        delete[] mac;
    }

    Macierz(Macierz &m);
    friend Macierz operator+ (const Macierz &m1, const Macierz &m2);
    friend Macierz operator- (const Macierz &m1, const Macierz &m2);
    friend Macierz operator* (const Macierz &m1, const Macierz &m2);
    friend std::ostream& operator<< (std::ostream& os, const Macierz &m2);
    friend Macierz operator= (const Macierz &m1);


};

Macierz operator+ (const Macierz &m1, const Macierz &m2);
Macierz operator- (const Macierz &m1, const Macierz &m2);
Macierz operator* (const Macierz &m1, const Macierz &m2);
std::ostream& operator<< (std::ostream& os,const Macierz &m2);
Macierz operator= (const Macierz &m1);



#endif //LABY_7_MACIERZE_MACIERZ_H
