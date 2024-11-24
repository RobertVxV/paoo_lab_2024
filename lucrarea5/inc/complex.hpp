#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <string>

class Complex {
public:
    Complex();
    Complex(int real, int imaginar);

    // Complex sum(const Complex& c);
    Complex operator+(const Complex& c) const;
    Complex& operator=(const Complex& c); 

    std::string to_string() const;

public:
    int real;
    int imaginar;
};

#endif // COMPLEX_HPP
