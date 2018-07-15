#include "dot_product.h"
#include "gtest/gtest.h"


TEST(DotProductTest, Trivial)
{
    const int SPARSE_VEC_SIZE = 100000;
    const int SPARSITY_FACTOR = 1000;

    auto A = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    auto B = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    auto A_cond = condensify(A);
    auto B_cond = condensify(B);
    auto A_map = sparseVectorToMap(A);
    auto B_map = sparseVectorToMap(B);

    auto res = dotProduct(A, B);
    EXPECT_EQ(dotProduct(A_map, B_map), res);
    EXPECT_EQ(dotProduct(A_map, B), res);
    EXPECT_EQ(dotProduct(A_map, B_map), res);
    EXPECT_EQ(dotProductCondSparse(A_cond, B), res);
    EXPECT_EQ(dotProductSparse(A_cond, B_cond), res);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
