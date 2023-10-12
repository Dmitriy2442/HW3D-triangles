#include "intersection.hpp"
#include "figures.hpp"

bool Triangle::intersect(const Triangle &T1, const Triangle &T2) {
    //To do: degenerate triangle pairs
    Plane P2 = T2.triangle_to_plane();


}