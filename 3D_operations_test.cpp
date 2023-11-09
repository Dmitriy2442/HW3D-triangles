#include <gtest/gtest.h>
#include "figures.hpp"
#include "geometric_operations.hpp"
#include "intersection.hpp"


TEST(Operations, VectorOperations) {
    EXPECT_EQ(Vector::scalar_product(Vector(1, 2, 3), Vector(2, 3, 4)), 20);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}