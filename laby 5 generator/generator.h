//
// Created by szymon on 05.11.2023.
//
#include <vector>
#include <cmath>
#include <iostream>

#ifndef __GENERATOR__
#define __GENERATOR__

class Histogram{
    int zakres;
    std::vector<double> histo;
public:

    Histogram(int Zakres) :
            zakres(Zakres), histo(zakres, 0) {}

    ~Histogram();

    void fill(double pop);
    void print();
    friend class Generator;
};

class Generator{
    long n;
    long w1,w2,w3;
    double seed;
    double pomoc;
    double pop;
    Histogram h = Histogram(10);

public:
    Generator(long N, double a, double c, double m, long s) :
            n(N), w1(a), w2(c), w3(m), seed(s) {
        pop = seed;
        for(int i = 0; i < n; i++){
            pomoc = long(w1*pop + w2) % w3;
            pop = pomoc / w3;
            std::cout << pop << " ";
            h.fill(pop);
        }
        std::cout << std::endl;
        h.print();
    }

    ~Generator();
    friend class Histogram;
};

#endif


