#ifndef 2D_FIGURES_HPP
#define 2D_FIGURES_HPP

namespace GEO_2D {
    class Point {
    private:
        float x, y;

    public:
        Point(): x(0.0f), y(0.0f) {}
        Point(float x_comp, float y_comp): x(x_comp), y(y_comp) {}

    }

    class Vector {
    private:
        float x, y;

    public:
        Vector(): x(0.0f), y(0.0f) {}
        Vector(float x_comp, float y_comp): x(x_comp), y(y_comp) {}
    }

    class Segment {
    private:
        Point P1, P2;
    }

    class Triangle {
    private: 
        Point V1, V2, V3;

    public:
        Triangle(): V1(Point()), V2(Point()), V3(Point()) {}
        Triangle(Point &Vertice1, Point &Vertice2, Point &Vertice3): V1(Vertice1), V2(Vertice2), V3(Vertice3) {}

        
    }
}
#endif /*2D_FIGURES_HPP*/