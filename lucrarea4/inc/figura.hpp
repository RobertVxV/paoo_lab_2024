#ifndef FIGURA_HPP
#define FIGURA_HPP

class Figura {
public:
    virtual double arie() const = 0;
    virtual double perimetru() const = 0;
    virtual ~Figura() = default;  //destructor
};

#endif // FIGURA_HPP