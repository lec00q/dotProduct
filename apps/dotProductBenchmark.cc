#include <unordered_map>
#include <vector>
#include <iostream>

#include "benchmark/benchmark.h"
#include "dot_product.h"

using namespace std;

const int SPARSE_VEC_SIZE = 100000;


static void BM_dotProduct(benchmark::State& state) {
    vector<int> A = sparseVector(SPARSE_VEC_SIZE);
    vector<int> B = sparseVector(SPARSE_VEC_SIZE);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(dotProduct(A, B));
    }
}
BENCHMARK(BM_dotProduct);


static void BM_dotProductMap(benchmark::State& state) {
    vector<int> A = sparseVector(SPARSE_VEC_SIZE);
    unordered_map<int, int> map_A = sparseVectorToMap(A);
    vector<int> B = sparseVector(SPARSE_VEC_SIZE);
    unordered_map<int, int> map_B = sparseVectorToMap(B);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(dotProduct(map_A, map_B));
    }
}
BENCHMARK(BM_dotProductMap);


static void BM_dotProductVecMap(benchmark::State& state) {
    vector<int> A = sparseVector(SPARSE_VEC_SIZE);
    unordered_map<int, int> map_A = sparseVectorToMap(A);
    vector<int> B = sparseVector(SPARSE_VEC_SIZE);
    unordered_map<int, int> map_B = sparseVectorToMap(B);

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(dotProduct(map_A, B));
    }
}
BENCHMARK(BM_dotProductVecMap);


static void BM_dotProductSparseVec(benchmark::State& state) {
    vector<int> A = sparseVector(SPARSE_VEC_SIZE);
    vector<int> A_cond = condensify(A);
    vector<int> B = sparseVector(SPARSE_VEC_SIZE);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(dotProductCondSparse(A_cond, B));
    }
}
BENCHMARK(BM_dotProductSparseVec);


static void BM_dotProductSparseVec2(benchmark::State& state) {
    vector<int> A = sparseVector(SPARSE_VEC_SIZE);
    vector<int> A_cond = condensify(A);
    vector<int> B = sparseVector(SPARSE_VEC_SIZE);
    vector<int> B_cond = condensify(B);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(dotProductSparse(A_cond, B_cond));
    }
}
BENCHMARK(BM_dotProductSparseVec2);


BENCHMARK_MAIN();
