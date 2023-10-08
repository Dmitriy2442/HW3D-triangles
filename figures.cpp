#include <iostream>
#include <cmath>
#include "figures.hpp"
#include "geometric_operations.hpp"

bool equal(const float a, const float b) {
    return (std::abs(a-b) < EPSILON);
}

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

Vector::Vector(const Point &point1, const Point &point2) {
    x = point2.get_x() - point1.get_x();
    x = point2.get_y() - point1.get_y();
    x = point2.get_z() - point1.get_z();
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

Vector Vector::operator * (const float coeff) const {
    Vector mul(x*coeff, y*coeff, z*coeff);
    return mul;
}

Vector Vector::operator = (const Vector &vec) {
    x = vec.get_x();
    y = vec.get_y();
    z = vec.get_z();
    return Vector(x, y, z);
} 

float Vector::abs_value() const {
    return std::sqrt(x*x + y*y + z*z);
}

Line::Line() {
    Point p0 = Point(0, 0, 0);
    Vector vec = Vector(0, 0, 0);
    P = p0;
    d = vec;
}

Line::Line(const Point &p0, const Vector &vec) {
    P = p0;
    d = vec;
}

Line::Line(const Point &p1, const Point &p2) {
    P = p1;
    d = Vector(p1, p2);
}

Point Line::get_point() const {
    return P;
}

Vector Line::get_direction() const {
    return d;
}

Triangle::Triangle() {
    V1 = Point(0, 0, 0);
    V2 = Point(0, 0, 0);
    V3 = Point(0, 0, 0);
}

Triangle::Triangle(const Point &vertice1, const Point &vertice2, const Point &vertice3) {
    V1 = vertice1;
    V2 = vertice2;
    V3 = vertice3;
}

Plane Triangle::triangle_plane() const {
    Vector n = vector_product(Vector(V1, V2), Vector(V2, V3));
    return Plane(V1, n);
}