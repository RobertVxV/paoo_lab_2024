#include <iostream>
#include <complex.hpp>

int main() {
    // Create and display two Complex numbers
    Complex c1(1, 2);
    Complex c2(3, 4);

    std::cout << "c1: " << c1.to_string() << std::endl;
    std::cout << "c2: " << c2.to_string() << std::endl;

    // Add and assign the result to c1
    c1 = c1 + c2;

    // Display the sum
    std::cout << "Sum: " << c1.to_string() << std::endl;

    // Demonstrate self-assignment
    c1 = c1;

    // Display the value after self-assignment
    std::cout << "After self-assignment, c1: " << c1.to_string() << std::endl;

    return 0;
}
