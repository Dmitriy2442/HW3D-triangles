#include "geometric_operations.hpp"
#include <vector>
#include "figures.hpp"

std::vector<float> Triangle::calc_signed_distances(const Triangle &T1, const Plane &P2) {
    std::vector<float> d(3);
    d[0] = P2.signed_dist(T1.V1);
    d[1] = P2.signed_dist(T1.V2);
    d[2] = P2.signed_dist(T1.V3);
    return d;
}

std::vector<float> Triangle::calc_projections(const Line &L, const Triangle &T) {
    std::vector<float> p(3);
    p[0] = L.projection(T.V1);
    p[1] = L.projection(T.V2);
    p[2] = L.projection(T.V3);
    return p;
}

Triangle Triangle::rearrange(std::vector<float> &d) const {
    float a;
    Point P;
    if (d[0] * d[2] > 0)
        return *this;
    else if (d[0] * d[1] > 0) {
        a = d[1];
        d[1] = d[2];
        d[2] = a;
        return Triangle(V1, V3, V2);
    }
    else if (d[1] * d[2] > 0) {
        a = d[1];
        d[1] = d[0];
        d[0] = a;
        return Triangle(V2, V1, V3);
    }
    return Triangle();
}

