#include <iostream>
#include "figures.hpp"

Point::Point() {
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(const float x_coord, const float y_coord, const float z_coord) {
    x = x_coord;
    y = y_coord;
    z = z_coord;
}

float Point::get_x() const {
    return x;
}

float Point::get_y() const {
    return y;
}

float Point::get_z() const {
    return z;
}

Vector::Vector() {
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(const float x_comp, const float y_comp, const float z_comp) {
    x = x_comp;
    y = y_comp;
    z = z_comp;
}

float Vector::get_x() const {
    return x;
}

float Vector::get_y() const {
    return y;
}

float Vector::get_z() const {
    return z;
}

Vector Vector::operator + (const Vector &vec) const {
    Vector sum(x + vec.get_x(), y + vec.get_y(), z + vec.get_z());
    return sum;
}

Vector Vector::operator * (const float &coeff) const {
    Vector mul(x*coeff, y*coeff, z*coeff);
    return mul;
}

Vector Vector::operator = (const Vector vec) {
    x = vec.get_x();
    y = vec.get_y();
    z = vec.get_z();
    return Vector(x, y, z);
} 


Line::Line() {
    Point p_0 = Point(0, 0, 0);
    Vector vec = Vector(0, 0, 0);
    P = p_0;
    d = vec;
}

Line::Line(const Point &p_0, const Vector &vec) {
    P = p_0;
    d = vec;
}

Point Line::get_point() const {
    return P;
}

Vector Line::get_direction() const {
    return d;
}

int main() {
    Vector vec1 = Vector(2, 3, 4);
    Vector vec2 = Vector(3, 4, 5);
    float coeff = 5;
    Vector vec3 = vec1 * coeff;
    std::cout << vec3.get_x() << vec3.get_y() << vec3.get_z() << std::endl;
}
