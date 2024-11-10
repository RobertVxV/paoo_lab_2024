#include <figura.hpp>

#ifndef DREPTUNGI_HPP
#define DREPTUNGI_HPP

class Dreptunghi : public Figura {
public:
    Dreptunghi(double latura1, double latura2);
    double arie() const override;
    double perimetru() const override;

    Dreptunghi(const Dreptunghi&) = delete;
    Dreptunghi& operator=(const Dreptunghi&) = delete;

private:
    double latura1;
    double latura2;
};

#endif // DREPTUNGI_HPP