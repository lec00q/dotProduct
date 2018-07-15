#include <unordered_map>
#include <vector>


std::vector<int> sparseVector(unsigned int size);
std::unordered_map<int, int> sparseVectorToMap(const std::vector<int> &A);
std::vector<int> condensify(const std::vector<int> &A);

long dotProduct(const std::vector<int> &A, const std::vector<int> &B);
long dotProduct(const std::unordered_map<int, int> &A, const std::unordered_map<int, int> &B);
long dotProduct(const std::unordered_map<int, int> &A, const std::vector<int> &B);
long dotProductCondSparse(const std::vector<int> &A, const std::vector<int> &B);
long dotProductSparse(const std::vector<int> &A, const std::vector<int> &B);
