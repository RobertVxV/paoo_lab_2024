#include <dreptunghi.hpp>

Dreptunghi::Dreptunghi(double latura1, double latura2) {
    this->latura1 = latura1;
    this->latura2 = latura2;
}

double Dreptunghi::arie() const {
    return latura1 * latura2;
}

double Dreptunghi::perimetru() const {
    return 2 * (latura1 + latura2);
}