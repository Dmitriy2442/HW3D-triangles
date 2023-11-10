#ifndef 2D_FIGURES_HPP
#define 2D_FIGURES_HPP

class 2D_Point {
private:
    float x, y;

public:
    2D_Point(): x(0.0f), y(0.0f) {}
    2D_Point(float x_comp, float y_comp): x(x_comp), y(y_comp) {}

}

class 2D_Vector {
private:
    float x, y;

public:
    2D_Vector(): x(0.0f), y(0.0f) {}
    2D_Vector(float x_comp, float y_comp): x(x_comp), y(y_comp) {}
}

class 2D_Segment {
private:
    2D_Point P1, P2;
}

#endif /*2D_FIGURES_HPP*/