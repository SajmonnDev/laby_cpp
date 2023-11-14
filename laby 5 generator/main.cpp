//
// Created by szymon on 05.11.2023.
//

#include <iostream>
#include "generator.h"

int main(){
    int n;
    double a,c,m,s;
    std::cout << "Podaj ile liczb ma zostac wygenerowanych, wspolczynniki generatora oraz jego ziarno." << std::endl;
    std::cin >> n >> a >> c >> m >> s;
    Generator gen(n,a,c,m,s);

    //Histogram h1;
    //h1.fill(gen);
    //h1.print();

    return 0;
}
