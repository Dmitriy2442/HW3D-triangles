#include "GEO_2D_figures.hpp"
//#include "GEO_2D_operations.hpp"
#include <iostream>

int main() {
    GEO_2D::Point P(1.f, 2.f);
    GEO_2D::Vector vec = P.vec();
    std::cout << vec.abs() << std::endl;
}