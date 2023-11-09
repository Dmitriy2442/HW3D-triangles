#include <vector>
#include "intersection.hpp"
#include "figures.hpp"

bool Triangle::intersect(const Triangle &T1, const Triangle &T2) {
    //To do: degenerate triangle pairs
    std::vector<float> d;
    std::vector<float> p;
    const Plane P2 = T2.triangle_to_plane();
    const Plane P1 = T1.triangle_to_plane();
    const Line L = Plane::planes_to_line(P1, P2);

/*    d = Triangle::calc_signed_distances(P1, P2, T1, T2);

    if (((d[0] > 0) && (d[1] > 0) && (d[2] > 0))||((d[3] < 0) && (d[4] < 0) && (d[5] < 0)))
        return 0;
    if (((d[0] > 0) && (d[1] > 0) && (d[2] > 0))||((d[3] < 0) && (d[4] < 0) && (d[5] < 0)))
        return 0;

    if ((equal(d[0], 0))&&(equal(d[1], 0))&&(equal(d[2], 0))) {
        //Complanar triangles case
    }*/

//    Triangle T1_rearr = T1.rearrange();
//    Triangle T1_rearr = T2.rearrange();

//    p = Triangle::calc_projections(L, T1, T2);
}