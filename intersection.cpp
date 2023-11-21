#include "intersection.hpp"
#include <iostream>

bool Triangle::intersect(const Triangle &T1, const Triangle &T2) {
    float t1_T1 = 0, t2_T1 = 0, t1_T2 = 0, t2_T2 = 0;
    //To do: degenerate triangle pairs
    std::vector<float> d_T1(3);
    std::vector<float> d_T2(3);

    std::vector<float> p_T1(3);
    std::vector<float> p_T2(3);

    const Plane P2 = T2.triangle_to_plane();
    const Plane P1 = T1.triangle_to_plane();
    const Line L = Plane::planes_to_line(P1, P2);
    d_T1 = Triangle::calc_signed_distances(T1, P2);
    d_T2 = Triangle::calc_signed_distances(T2, P1);

    if (((d_T1[0] > 0) && (d_T1[1] > 0) && (d_T1[2] > 0))||((d_T2[0] < 0) && (d_T2[1] < 0) && (d_T2[2] < 0)))
        return 0;
    if (((d_T1[0] > 0) && (d_T1[1] > 0) && (d_T1[2] > 0))||((d_T2[0] < 0) && (d_T2[1] < 0) && (d_T2[2] < 0)))
        return 0;

    if ((equal(d_T1[0], 0))&&(equal(d_T1[1], 0))&&(equal(d_T1[2], 0))) {
        //Complanar triangles case
    }

/*    for (int i = 0; i < 6; i++)
        std::cout << d_T1[i] << " " << d_T2[i] << std::endl;*/

    Triangle T1_rearr = T1.rearrange(d_T1);
    Triangle T2_rearr = T2.rearrange(d_T2);

    p_T1 = Triangle::calc_projections(L, T1);
    p_T2 = Triangle::calc_projections(L, T2);

    t1_T1 = p_T1[0] + (p_T1[1] - p_T1[0]) * d_T1[0] / (d_T1[0] - d_T1[1]);
    t2_T1 = p_T1[1] + (p_T1[2] - p_T1[1]) * d_T1[1] / (d_T1[1] - d_T1[2]);
    t1_T2 = p_T2[0] + (p_T2[1] - p_T2[0]) * d_T2[0] / (d_T2[0] - d_T2[1]);
    t2_T2 = p_T2[1] + (p_T2[2] - p_T2[1]) * d_T2[1] / (d_T2[1] - d_T2[2]);

    std::cout << t1_T1 << " " << t2_T1 << std::endl << t1_T2 << " " << std::endl;

    if (equal(t1_T1, t1_T2) || equal(t1_T1, t2_T2) || equal(t1_T2, t2_T1) || equal(t2_T1, t2_T2))
        return 1;
    if (t2_T1 < t1_T1)
        std::swap(t1_T1, t2_T1);
    if (t2_T2 < t1_T2)
        std::swap(t1_T2, t2_T2);
    
    if (((t1_T1 < t1_T2)&&(t1_T2 < t2_T1)) || ((t1_T1 < t2_T2)&&(t1_T2 < t2_T1)) || ((t1_T2 < t1_T1)&&(t1_T1 < t2_T2)) || ((t1_T2 < t2_T1)&&(t2_T1 < t2_T2)))
        return 1;
    return 0;
}