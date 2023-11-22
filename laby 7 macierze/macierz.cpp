//
// Created by szymon on 22.11.2023.
//
#include "macierz.h"
#include <iostream>

Macierz::Macierz(int N, int M, float l) : n(N), m(M) {
    mac = new float*[n];
    for(int i = 0; i < n; i++) {
        mac[i] = new float[m];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mac[i][j] = l;
        }
    }
}
Macierz operator= (const Macierz &m1){

}

Macierz::Macierz(Macierz &mtrx) : n(mtrx.n), m(mtrx.m) {
    mac = new float *[n];
    for(int i = 0; i < n; i++) {
        mac[i] = new float[m];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mac[i][j] = mtrx.mac[i][j];
        }
    }
}

Macierz::Macierz() {
    n = 0;
    m = 0;
    mac = nullptr;
}


Macierz operator+ (const Macierz &m1, const Macierz &m2) {
    if (m1.n == m2.n && m1.m == m2.m) {
        Macierz m3(m1.n, m1.m, 0);
        for (int i = 0; i < m1.n; i++) {
            for (int j = 0; j < m1.m; j++) {
                m3.mac[i][j] = m1.mac[i][j] + m2.mac[i][j];
            }
        }
        return m3;
    }
    else{
        std::cout << "Nie mozna dodac macierz o roznych wymiarach" << std::endl;
        Macierz m4 = Macierz();
        return m4;
    }
}

Macierz operator- (const Macierz &m1, const Macierz &m2){
    Macierz m3 = Macierz();
    if(m1.n == m2.n && m1.m == m2.m){
        Macierz m4 = Macierz(m1.n, m1.m, 0);
        for(int i = 0; i < m1.n; i++) {
            for (int j = 0; j < m1.m; j++) {
                m4.mac[i][j] = m1.mac[i][j] - m2.mac[i][j];
            }
        }
        return m4;
    }
    else{
        std::cout << "Nie mozna odjac macierz o roznych wymiarach" << std::endl;
    }
    return m3;
}

Macierz operator* (const Macierz &m1, const Macierz &m2){
    Macierz m3 = Macierz();
    if(m1.n == m2.m){
        Macierz m4 = Macierz(m1.n, m2.m, 0);
        for(int i = 0; i < m1.n; i++) {
            for (int j = 0; j < m2.m; j++) {
                for(int k = 0; k < m1.m; k++){
                    m4.mac[i][j] += m1.mac[i][k] * m2.mac[k][j];
                    std::cout<< "m4: " << m4.mac[i][j] << " m1: " << m1.mac[i][k] << " m2: " << m2.mac[k][j] << std::endl;
                }
            }
        }
        return m4;
    }
    else{
        std::cout << "Nie mozna pomnozyc macierz o roznych kolumnach i wierszach" << std::endl;
    }
    return m3;
}

std::ostream& operator<< (std::ostream& os,const Macierz &m2){
    for(int i = 0; i < m2.n; i++){
        for(int j = 0; j < m2.m; j++){
            os << m2.mac[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}




