#include <iostream>
#include <fstream>
#include <string>
#include "figures.hpp"
#include "intersection.hpp"

int main() {
    std::ofstream logs;
    logs.open("logs.txt");

    Vector vec1 = Vector(0, 0, 0);
    Vector vec2 = Vector(3, 6, 8);
    Point p1 = Point(0, 0, 0);
    Point p2 = Point(1, 0, 0);
    Point p3 = Point(1, 1, 0);
    Triangle T1 = Triangle(p1, p2, p3);
    Triangle T2 = Triangle(Point(), Point(), Point());
    Plane P = T1.triangle_to_plane();
    P.logs_out(logs, "P");

    std::cout << Triangle::intersect(T1, T2) << std::endl;
}