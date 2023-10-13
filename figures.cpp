#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include "geometric_operations.hpp"
#include "figures.hpp"

bool equal(const float a, const float b) {
    return (std::abs(a-b) < EPSILON);
}

//---------------------------------------------------------------------------------------------------------------------
//Vector part

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

void Vector::logs_out(std::ofstream &log_file, std::string name) {
    log_file << "Vector " << name << ": " << x << " " << y << " " << z << std::endl;
}

Vector Vector::operator + (const Vector &vec) const {
    Vector sum(x + vec.x, y + vec.y, z + vec.z);
    return sum;
}

Vector Vector::operator * (const float coeff) const {
    Vector mul(x*coeff, y*coeff, z*coeff);
    return mul;
}

Vector Vector::operator = (const Vector &vec) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return Vector(x, y, z);
} 

float Vector::scalar_product(const Vector &vec1, const Vector &vec2) {
    return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

Vector Vector::vector_product(const Vector &vec1, const Vector &vec2) {
    return Vector((vec1.y * vec2.z - vec1.z * vec2.y), -1*(vec1.x * vec2.z - vec1.z * vec2.x), (vec1.x * vec2.y - vec1.y * vec2.x));
}

bool Vector::are_collinear(const Vector &vec1, const Vector &vec2) {
    return (equal(vec1.abs_value() * vec2.abs_value(), Vector::scalar_product(vec1, vec2)));
}

Point Vector::vector_to_point() {
    return Point(x, y, z);
}

float Vector::abs_value() const {
    return std::sqrt(x*x + y*y + z*z);
}

//---------------------------------------------------------------------------------------------------------------------
//Point part

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

void Point::logs_out(std::ofstream &log_file, std::string name) {
    log_file << "Point " << name << ": " << x << " " << y << " " << z << std::endl;
}

Vector Point::points_to_vector(const Point &p1, const Point &p2) {
    float x = p1.x - p2.x;
    float y = p1.y - p2.y;
    float z = p1.z - p2.z;
    return Vector(x, y, z);
}

Vector Point::vec() const {
    return Vector(x, y, z);
}

//---------------------------------------------------------------------------------------------------------------------
//Line part

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
    d = Point::points_to_vector(p1, p2);
}

//---------------------------------------------------------------------------------------------------------------------
//Plane part

Plane::Plane() {
    d = 0;
    n = Vector();
}

Plane::Plane(const float d_0, const Vector &n_0) {
    d = d_0;
    n = n_0;
}

void Plane::logs_out(std::ofstream &log_file, std::string name) {
    log_file << "Plane " << name << ": " << std::endl;
    log_file << "float d: " << d << std::endl;
    n.logs_out(log_file, "n");
    log_file << std::endl;
}

float Plane::signed_dist(const Point &p) {
    return (Vector::scalar_product(p.vec(), n) + d);
}

Line Plane::planes_to_line(const Plane &P1, const Plane &P2) {
    float s1, s2, a, b, n1n2, n1sqr, n2sqr;
    Vector P;
    Vector d = Vector::vector_product(P1.n, P2.n);
    s1 = P1.d;
    s2 = P2.d;
    n1n2 = Vector::scalar_product(P1.n, P2.n);
    n1sqr = Vector::scalar_product(P1.n, P1.n);
    n2sqr = Vector::scalar_product(P2.n, P2.n);
    a = (s2 * n1n2 - s1 * n2sqr) / (n1n2*n1n2 - n1sqr * n2sqr);
    b = (s1 * n1n2 - s2 * n1sqr) / (n1n2*n1n2 - n1sqr * n2sqr);
    P = P1.n*a + P2.n*b;
}

//---------------------------------------------------------------------------------------------------------------------
//Triangle part

Triangle::Triangle() {
    V1 = Point();
    V2 = Point();
    V3 = Point();
}

Triangle::Triangle(const Point &vertice1, const Point &vertice2, const Point &vertice3) {
    V1 = vertice1;
    V2 = vertice2;
    V3 = vertice3;
}

Point Triangle::get_V1() const {
    return V1;
}
Point Triangle::get_V2() const {
    return V2;
}
Point Triangle::get_V3() const {
    return V3;
}

Plane Triangle::triangle_to_plane() const {
    Vector n = Vector::vector_product(Point::points_to_vector(V2, V1), Point::points_to_vector(V3, V1));
    float d = -1 * Vector::scalar_product(n, V1.vec());
    return Plane(d, n);
}