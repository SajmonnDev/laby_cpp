
//
// Created by szymon on 05.11.2023.
//
#include "gen.h"



Generator::~Generator() = default;

void Histogram::print(){
    for(int i = 0; i < zakres ; i++){
        std::cout << double(i)/double(zakres) << ": " << histo[i] << std::endl;
//        for(int j = 0; j < histo[i]; j++){
//            std::cout << "*";
//        }
//        std::cout << std::endl;
    }
}

void Histogram::fill(double pop){
    int index = int(zakres*pop);
    histo[index]++;
}

Histogram::~Histogram() = default;