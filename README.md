# DotProduct

This repo is used to test different implementations of [dot product](https://en.wikipedia.org/wiki/Dot_product) for sparse vectors in C++.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

To get started you need to install the following libries for your OS:

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

## Authors

See the list of [authors](AUTHORS) in this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


