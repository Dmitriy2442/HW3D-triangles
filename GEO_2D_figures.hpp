#ifndef GEO_2D_FIGURES_HPP
#define GEO_2D_FIGURES_HPP

#define EPSILON 0.00001
bool equal2(const float a, const float b);

namespace GEO_2D {

    class Vector {
    private:
        float x, y;

    public:
        Vector(): x(0.0f), y(0.0f) {}
        Vector(float x_comp, float y_comp): x(x_comp), y(y_comp) {}

        Vector operator + (const Vector &vec) const;
        Vector operator - (const Vector &vec) const;
        Vector operator * (const float coeff) const;
        Vector operator = (const Vector &vec);

        float get_x() const;
        float abs() const;
        Vector ort() const;
        static float kross(const Vector &L1, const Vector &L2);
        Point point() const;
    };

    class Point {
    private:
        float x, y;

    public:
        Point(): x(0.0f), y(0.0f) {}
        Point(float x_comp, float y_comp): x(x_comp), y(y_comp) {}

        Vector vec() const;
        static Vector points_to_vector(const Point &p1, const Point &p2);
    };

    class Line {
    private:
        Point P;
        Vector d;
    public:
        Line(): P(Point()), d(Vector()) {}
        Line(const Point &p0, const Vector &vec): P(p0), d(vec) {}
//        Line(const Point &p1, const Point &p2): P(p1), d(Point::points_to_vector(p1, p2)) {}
        static Point lines_crossing(const Line &L1, const Line &L2);
        float signed_dist(const Point &P0);
    };

    class Triangle {
    private: 
        Point V1, V2, V3;

    public:
        Triangle(): V1(Point()), V2(Point()), V3(Point()) {}
        Triangle(Point &Vertice1, Point &Vertice2, Point &Vertice3): V1(Vertice1), V2(Vertice2), V3(Vertice3) {}

        static bool intersection(Triangle &T1, Triangle &T2);
    };
}
#endif /*GEO_2D_FIGURES_HPP*/