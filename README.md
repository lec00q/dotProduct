# DotProduct

This repo is used to test different implementations of [dot product](https://en.wikipedia.org/wiki/Dot_product) for sparse vectors in C++.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

To get started you need to install the following libraries for your OS:

* [Google Test](https://github.com/google/googletest): used for running unit tests
* [Google Benchmark](https://github.com/google/benchmark): used for running benchmark tests

You will also need CMake to build the project.

### Installing

Create a build folder, name it `build` for instance, and use CMake to build the two executables:

```
mkdir build && cd build
cmake ../
make install
```

This will create a `bin` directory with two artifacts inside, one is for testing, the other one is for benchmarking the different functions.

## Implementation details

I have implemented the dot product operation in different flavors, using a combination of `vector` and `unordered_map` representations.

I use a default of 100.000 vector elements, of which 100 are set to an integer value greater than 0. This can be easily changed in code.

I am _not_ taking into account the space-time complexity needed to create the initial data structure: they are given "for-free". My objective is to test the dot product operation in isolation.

Please note that the compiler optimization are turned off _on purpose_, as they will give you results which are out of the scopes of this analysis.

### Benchmarks

These are the latest results on my local dev machine (MBP Retina Late 2013 2.3GHz):

```
---------------------------------------------------------------
Benchmark                        Time           CPU Iterations
---------------------------------------------------------------
BM_dotProduct                21614 ns      21602 ns      31470
BM_dotProductMap               819 ns        818 ns     836150
BM_dotProductVecMap            200 ns        200 ns    3403693
BM_dotProductSparseVec          58 ns         58 ns   11994928
BM_dotProductSparseVec2        293 ns        292 ns    2573984
```

You can see that the clear winner uses a combination of two different vector representation. The first is a standard 100000-size vector with a lot of 0s. The other is a vector which holds tuples (index, value), storing only non-zero values. For example, given the following input sparse vector:

```
[1 0 0 0 2 0 0 1 0 0 63 0 0 0 0 0 0]
```

this is its condensed representation:

```
[0, 1, 4, 2, 7, 1, 10, 63]
```

However, this is clearly not the winner in terms of space usage. Using two "condensed" vector could be considered a good compromise.

### Notes on testing

Given the nature of sparse vectors, the dot product may often give 0 as a result. To be sure that the implementation is correct, I suggest to run the unit tests a certain minimum number of times:

```
bin/dotProduct_test --gtest_repeat=100
```

## Authors

See the list of [authors](AUTHORS) in this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


