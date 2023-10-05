#include <iostream>
#include "figures.hpp"
#include "geometric_operations.hpp"

int main() {
    Vector vec1 = Vector(2, 3, 4);
    Vector vec2 = Vector(3, 4, 5);
    std::cout << scalar_product(vec1, vec2) << std::endl;
}