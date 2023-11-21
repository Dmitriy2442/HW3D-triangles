#ifndef FIGURES_HPP
#define FIGURES_HPP

#include <fstream>
#include <string>
#include <vector>

#define EPSILON 0.00001
bool equal(const float a, const float b);

class Point;

class Vector {
private:
    float x, y, z;

public:
    Vector(): x(0.0f), y(0.0f), z(0.0f) {}
    Vector(const float x_comp, const float y_comp, const float z_comp): x(x_comp), y(y_comp), z(z_comp) {} 

    void logs_out(std::ofstream &log_file, std::string name);

    Vector operator + (const Vector &vec) const;
    Vector operator - (const Vector &vec) const;
    Vector operator * (const float coeff) const;
    Vector operator = (const Vector &vec);

    static float scalar_product(const Vector &vec1, const Vector &vec2);
    static Vector vector_product(const Vector &vec1, const Vector &vec2);
    static bool are_collinear(const Vector &vec1, const Vector &vec2);

    Point vector_to_point();
    float abs_value() const;
};

class Point {
private:
    float x, y, z;

public:
    Point(): x(0.0f), y(0.0f), z(0.0f) {}
    Point(const float x_coord, const float y_coord, const float z_coord): x(x_coord), y(y_coord), z(z_coord) {}

    void logs_out(std::ofstream &log_file, std::string name);

    static Vector points_to_vector(const Point &p1, const Point &p2);
    Vector vec() const;
};

class Line {
private:
    Point P;
    Vector d;
public:
    Line(): P(Point()), d(Vector()) {}
    Line(const Point &p0, const Vector &vec): P(p0), d(vec) {}
    Line(const Point &p1, const Point &p2): P(p1), d(Point::points_to_vector(p1, p2)) {}

    float projection(const Point &P) const;
};

class Plane {
private:
    float d;
    Vector n;
public:
    Plane(): d(0.0f), n(Vector()) {}
    Plane(const float d0, const Vector &n0): d(d0), n(n0) {}

    void logs_out(std::ofstream &log_file, std::string name);
    float signed_dist(const Point &p) const;
    static Line planes_to_line(const Plane &P1, const Plane &P2);
};

class Triangle {
private:
    Point V1, V2, V3;
public:
    Triangle(): V1(Point()), V2(Point()), V3(Point()) {}
    Triangle(const Point &vertice1, const Point &vertice2, const Point &vertice3): V1(vertice1), V2(vertice2), V3(vertice3) {}

    Point get_V1() const;
    Point get_V2() const;
    Point get_V3() const;

    void logs_out(std::ofstream &log_file, std::string name);
    Plane triangle_to_plane() const;
    static bool intersect(const Triangle &T1, const Triangle &T2);
    static std::vector<float> calc_signed_distances(const Triangle &T1, const Plane &P2);      //Returns array of distances, first from vertices of T1 to P2, then from vertices of T2 to P1
    static std::vector<float> calc_projections(const Line &L, const Triangle &T);
    Triangle rearrange(std::vector<float> &d) const;
};

#endif /*FIGURES_HPP*/