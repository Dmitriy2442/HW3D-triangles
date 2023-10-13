#include "intersection.hpp"
#include "figures.hpp"

bool Triangle::intersect(const Triangle &T1, const Triangle &T2) {
    //To do: degenerate triangle pairs
    Plane P2 = T2.triangle_to_plane();
    Plane P1 = T1.triangle_to_plane();
    float d1_T1 = P2.signed_dist(T1.get_V1());
    float d2_T1 = P2.signed_dist(T1.get_V2());
    float d3_T1 = P2.signed_dist(T1.get_V2());
    float d1_T2 = P1.signed_dist(T2.get_V1());
    float d2_T2 = P1.signed_dist(T2.get_V2());
    float d3_T2 = P1.signed_dist(T2.get_V2());

    if (((d1_T1 > 0) && (d2_T1 > 0) && (d3_T1 > 0))||((d1_T1 < 0) && (d2_T1 < 0) && (d3_T1 < 0)))
        return 0;
    if (((d1_T2 > 0) && (d2_T2 > 0) && (d3_T2 > 0))||((d1_T2 < 0) && (d2_T2 < 0) && (d3_T2 < 0)))
        return 0;

    if ((equal(d1_T1, 0))&&(equal(d2_T1, 0))&&(equal(d3_T1, 0))) {
        //Complanar triangles case
    }
    
}