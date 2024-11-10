#include <iostream>
#include <dreptunghi.hpp>

using namespace std;

int main() {
    // Crearea unui dreptunghi cu laturile 3.0 și 4.0
    Dreptunghi d1(3.0, 4.0);
    Dreptunghi d2(1.0, 5.0);

    Dreptunghi d3 = new Dreptunghi();

    // Dreptunghi d3 = d1; // Eroare de compilare - use of deleted function

    //d2 = d1; // Eroare de compilare - use of deleted function


    // Afișarea ariei și perimetrului
    std::cout << "Aria dreptunghiului: " << d1.arie() << std::endl;
    std::cout << "Perimetrul dreptunghiului: " << d1.perimetru() << std::endl;

    std::cout << "Aria dreptunghiului: " << d2.arie() << std::endl;
    std::cout << "Perimetrul dreptunghiului: " << d2.perimetru() << std::endl;

    return 0;
}