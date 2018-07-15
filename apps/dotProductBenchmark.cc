#include <unordered_map>
#include <vector>
#include <iostream>

#include "benchmark/benchmark.h"
#include "dot_product.h"

using namespace std;

const int SPARSE_VEC_SIZE = 100000;
const int SPARSITY_FACTOR = 1000;


static void BM_dotProduct(benchmark::State& state) {
    vector<int> A = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    vector<int> B = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(dotProduct(A, B));
    }
}
BENCHMARK(BM_dotProduct);


static void BM_dotProductMap(benchmark::State& state) {
    vector<int> A = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    unordered_map<int, int> map_A = sparseVectorToMap(A);
    vector<int> B = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    unordered_map<int, int> map_B = sparseVectorToMap(B);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(dotProduct(map_A, map_B));
    }
}
BENCHMARK(BM_dotProductMap);


static void BM_dotProductVecMap(benchmark::State& state) {
    vector<int> A = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    unordered_map<int, int> map_A = sparseVectorToMap(A);
    vector<int> B = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    unordered_map<int, int> map_B = sparseVectorToMap(B);

    if (map_A.size() > map_B.size())
    {
        for (auto _ : state)
            benchmark::DoNotOptimize(dotProduct(map_B, A));
    }
    else
    {
        for (auto _ : state)
            benchmark::DoNotOptimize(dotProduct(map_A, B));
    }
}
BENCHMARK(BM_dotProductVecMap);


static void BM_dotProductSparseVec(benchmark::State& state) {
    vector<int> A = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    vector<int> A_cond = condensify(A);
    vector<int> B = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    vector<int> B_cond = condensify(B);

    if (A_cond.size() > B_cond.size())
    {
        for (auto _ : state)
            benchmark::DoNotOptimize(dotProductCondSparse(B_cond, A));
    }
    else
    {
        for (auto _ : state)
            benchmark::DoNotOptimize(dotProductCondSparse(A_cond, B));
    }
}
BENCHMARK(BM_dotProductSparseVec);


static void BM_dotProductSparseVec2(benchmark::State& state) {
    vector<int> A = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    vector<int> A_cond = condensify(A);
    vector<int> B = sparseVector(SPARSE_VEC_SIZE, SPARSITY_FACTOR);
    vector<int> B_cond = condensify(B);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(dotProductSparse(A_cond, B_cond));
    }
}
BENCHMARK(BM_dotProductSparseVec2);


BENCHMARK_MAIN();
