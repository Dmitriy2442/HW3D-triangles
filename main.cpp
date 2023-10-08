#include <iostream>
#include "figures.hpp"
#include "geometric_operations.hpp"

int main() {
    Vector vec1 = Vector(1, 2, 3);
    Vector vec2 = Vector(4, 5, 6);
    Vector vec3 = vector_product(vec1, vec2);
    std::cout << vec3.get_x() << vec3.get_y() << vec3.get_z() << std::endl;
}