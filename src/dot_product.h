#include <unordered_map>
#include <vector>

/**
 * @brief      Generate a sparse vector.
 *
 * @param[in]  size  The size of the resulting vector.
 *
 * @return     A sparse vector.
 */
std::vector<int> sparseVector(unsigned int size, unsigned int sparsity_factor);

/**
 * @brief      Convert a sparse vector into a map.
 *
 *             The map uses array index as keys.
 *
 * @param[in]  A     A sparse vector.
 *
 * @return     An equivalent map which stores only non-zero values.
 */
std::unordered_map<int, int> sparseVectorToMap(const std::vector<int> &A);

/**
 * @brief      Convert a sparse vector into its condensed representation.
 *
 * @param[in]  A     A sparse vector.
 *
 * @return     A reduced-size sparse vector.
 */
std::vector<int> condensify(const std::vector<int> &A);

long dotProduct(const std::vector<int> &A, const std::vector<int> &B);
long dotProduct(const std::unordered_map<int, int> &A, const std::unordered_map<int, int> &B);
long dotProduct(const std::unordered_map<int, int> &A, const std::vector<int> &B);
long dotProductCondSparse(const std::vector<int> &A, const std::vector<int> &B);
long dotProductSparse(const std::vector<int> &A, const std::vector<int> &B);
