#include <iostream>
#include <fstream>
#include <string>
#include "figures.hpp"
#include "intersection.hpp"

int main() {
    std::ofstream logs;
    logs.open("logs.txt");

    Point p1 = Point(1, 0, 0);
    Point p2 = Point(0, 1, 0);
    Point p3 = Point(0, 0, 1);
    Triangle T1 = Triangle(p1, p2, p3);
    Triangle T2 = Triangle(p1, Point(1, 0, 1), Point(0, 1, 1));
    Plane P = T1.triangle_to_plane();

    std::cout << Triangle::intersect(T1, T2) << std::endl;
}