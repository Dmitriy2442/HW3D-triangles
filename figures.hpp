#ifndef FIGURES_HPP
#define FIGURES_HPP

#define EPSILON 0.00001

bool equal(const float a, const float b);

class Point {
private:
    float x, y, z;

public:
    Point();
    Point(const float x_coord, const float y_coord, const float z_coord);

    float get_x() const;
    float get_y() const;
    float get_z() const;
};

class Vector {
private:
    float x, y, z;

public:
    Vector();
    Vector(const float x_comp, const float y_comp, const float z_comp);
    Vector(const Point &p1, const Point &p2);

    float get_x() const;
    float get_y() const;
    float get_z() const;

    Vector operator + (const Vector &vec) const;
    Vector operator * (const float coeff) const;
    Vector operator = (const Vector &vec);

    float abs_value() const;
};

class Line {
private:
    Point P;
    Vector d;
public:
    Line();
    Line(const Point &p0, const Vector &vec);
    Line(const Point &p1, const Point &p2);

    Point get_point() const;
    Vector get_direction() const;
};

class Plane {
private:
    Point P;
    Vector n;
public:
    Plane();
    Plane(const Point &P, const Vector &n);
};

class Triangle {
private:
    Point V1, V2, V3;
public:
    Triangle();
    Triangle(const Point &vertice1, const Point &vertice2, const Point &vertice3);

    Plane triangle_plane() const;
};

#endif /*FIGURES_HPP*/