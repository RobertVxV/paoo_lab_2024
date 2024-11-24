#include <complex.hpp>
#include <string>

Complex::Complex() {
    this->real = 0;
    this->imaginar = 0;
}

Complex::Complex(int real, int imaginar) {
    this->real = real;
    this->imaginar = imaginar;
}

Complex Complex::operator+(const Complex& c) const {
    Complex temp;
    temp.real = this->real + c.real;
    temp.imaginar = this->imaginar + c.imaginar;
    return temp;
}

//create a method that returns a reference to *this

//error: definition of implicitly-declared ‘constexpr Complex& Complex::operator=(const Complex&)’

Complex& Complex::operator=(const Complex& c) {
    if (this == &c) {
        return *this; // Handle self-assignment
    }
    // Copy all parts of the object
    this->real = c.real;
    this->imaginar = c.imaginar;
    return *this; // Return reference to *this
}


std::string Complex::to_string() const {
    return std::to_string(real) + " + " + std::to_string(imaginar) + "i";
}