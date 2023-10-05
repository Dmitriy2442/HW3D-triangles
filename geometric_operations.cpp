#include "geometric_operations.hpp"

float scalar_product(const Vector &vec1, const Vector &vec2) {
    return (vec1.get_x() * vec2.get_x() + vec1.get_y() * vec2.get_y() + vec1.get_z() * vec2.get_z());
}

bool are_collinear(const Vector &vec1, const Vector &vec2) {
    return (equal(vec1.abs_value() * vec2.abs_value(), scalar_product(vec1, vec2)));
}

