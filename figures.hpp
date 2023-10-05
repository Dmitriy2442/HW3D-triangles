#ifndef FIGURES_HPP
#define FIGURES_HPP

#define EPSILON 0.00001

bool equal(const float &a, const float &b);

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

    float get_x() const;
    float get_y() const;
    float get_z() const;

    Vector operator + (const Vector &vec) const;
    Vector operator * (const float &coeff) const;
    Vector operator = (const Vector vec);

    float abs_value() const;
};

class Line {
private:
    Point P;
    Vector d;
public:
    Line();
    Line(const Point &p_0, const Vector &vec);
    Line(const Point &p1, const Point &p2);

    Point get_point() const;
    Vector get_direction() const;
};

class Plane {

};

#endif /*FIGURES_HPP*/