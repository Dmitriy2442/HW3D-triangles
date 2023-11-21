#ifndef 2D_OPERATIONS_HPP
#define 2D_OPERATIONS_HPP

#include <vector>
#include "2D_figures.hpp"

namespace 2D {

    class Triangle {
    public:
        static bool intersection(Triangle &T1, Triangle &T2);
    }
}

#endif /*2D_OPERATIONS_HPP*/