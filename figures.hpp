#ifndef FIGURES_HPP
#define FIGURES_HPP

#include <fstream>
#include <string>

#define EPSILON 0.00001

bool equal(const float a, const float b);

class Vector {
private:
    float x, y, z;

public:
    Vector();
    Vector(const float x_comp, const float y_comp, const float z_comp);

    void logs_out(std::ofstream &log_file, std::string name);

    Vector operator + (const Vector &vec) const;
    Vector operator * (const float coeff) const;
    Vector operator = (const Vector &vec);

    static float scalar_product(const Vector &vec1, const Vector &vec2);
    static Vector vector_product(const Vector &vec1, const Vector &vec2);
    static bool are_collinear(const Vector &vec1, const Vector &vec2);

    float abs_value() const;
};

class Point {
private:
    float x, y, z;

public:
    Point();
    Point(const float x_coord, const float y_coord, const float z_coord);

    void logs_out(std::ofstream &log_file, std::string name);

    static Vector points_to_vector(const Point &p1, const Point &p2);
    Vector vec() const;
};

class Line {
private:
    Point P;
    Vector d;
public:
    Line();
    Line(const Point &p0, const Vector &vec);
    Line(const Point &p1, const Point &p2);
};

class Plane {
private:
    float d;
    Vector n;
public:
    Plane();
    Plane(const float d, const Vector &n_0);

    void logs_out(std::ofstream &log_file, std::string name);
    float signed_dist(Point &p);
};

class Triangle {
private:
    Point V1, V2, V3;
public:
    //Triangle() : v1(Point())
    Triangle();
    Triangle(const Point &vertice1, const Point &vertice2, const Point &vertice3);

    Plane triangle_to_plane() const;
    static bool intersect(const Triangle &T1, const Triangle &T2);
};

#endif /*FIGURES_HPP*/