#include "GEO_2D_figures.hpp"
#include "cmath"

bool equal2(const float a, const float b) {
    return (std::abs(a-b) < EPSILON);
}
namespace GEO_2D {

    Vector Vector::operator + (const Vector &vec) const {
        return Vector(x + vec.x, y + vec.y);
    }

    Vector Vector::operator - (const Vector &vec) const {
        return Vector(x - vec.x, y - vec.y);
    }

    Vector Vector::operator * (const float coeff) const {
        return Vector(coeff * x, coeff * y);
    }

    Vector Vector::operator = (const Vector &vec) {
        return Vector(vec.x, vec.y);
    }

    float Vector::get_x() const{
        return x;
    }

    float Vector::abs() const {
        return sqrt(x*x + y*y);
    }

    Vector Vector::ort() const {
        if (x == 0)
            return Vector(1, 0);
        return Vector(-y/x, 1.f);
    }

    float Vector::kross(const Vector &L1, const Vector &L2) {
        return (L1.x*L2.y - L2.x*L1.y);
    }

    Point Vector::point() const {
        return(Point(x, y));
    }

    Vector Point::vec() const {
        return Vector(x, y);
    }

    Vector Point::points_to_vector(const Point &p1, const Point &p2) {
        return (p1.vec() - p2.vec());
    }

    Point Line::lines_crossing(const Line &L1, const Line &L2) {
        float s = Vector::kross((L2.P.vec() - L1.P.vec()), L2.d)/Vector::kross(L1.d, L2.d);
        Vector vec_0 = L1.P.vec() + L1.d * s;
        return vec_0.point();
    }

    float Line::signed_dist(const Point &P0) {
        Point T = lines_crossing(*this, Line(P0, d.ort()));
        Vector vec = Point::points_to_vector(P0, T);
        float mod = vec.abs();
        if (vec.get_x() > 0)
            return mod;
        else if (vec.get_x() < 0)
            return -mod;
        else
            return 0.f;
    }

    bool Triangle::intersection(Triangle &T1, Triangle &T2) {
        
    }
}