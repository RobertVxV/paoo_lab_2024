#include <iostream>
#include <dreptunghi.hpp>

using namespace std;

int main() {
    
    Dreptunghi d1(3.0, 4.0);
    Dreptunghi d2(1.0, 5.0);

    // Dreptunghi d3 = new Dreptunghi(); // eroare de compilare - no matching function for call to 'Dreptunghi::Dreptunghi()'

    // Dreptunghi d3 = d1; // Eroare de compilare - use of deleted function

    //d2 = d1; // Eroare de compilare - use of deleted function


    // Afișarea ariei și perimetrului
    std::cout << "Aria dreptunghiului: " << d1.arie() << std::endl;
    std::cout << "Perimetrul dreptunghiului: " << d1.perimetru() << std::endl;

    std::cout << "Aria dreptunghiului: " << d2.arie() << std::endl;
    std::cout << "Perimetrul dreptunghiului: " << d2.perimetru() << std::endl;

    return 0;
}