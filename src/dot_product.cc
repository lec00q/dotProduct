#include <random>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>


using namespace std;


/**
 * @brief      Generate a sparse vector.
 *
 * @param[in]  size  The size of the resulting vector.
 *
 * @return     A sparse vector.
 */
vector<int> sparseVector(unsigned int size)
{
    uniform_int_distribution<int> distribution(1, 128);
    default_random_engine generator;

    vector<int> vec(size, 0);
    generate_n(vec.begin(), size / 1000, [&distribution, &generator]()
               { return distribution(generator); });

    random_device rd;
    mt19937 g(rd());
    shuffle(vec.begin(), vec.end(), g);

    return vec;
}


/**
 * @brief      Convert a sparse vector into a map.
 *
 *             The map uses array index as keys.
 *
 * @param[in]  A     A sparse vector.
 *
 * @return     An equivalent map which store values.
 */
unordered_map<int, int> sparseVectorToMap(const vector<int> &A)
{
    unordered_map<int, int> B;
    for (auto i = 0; i < A.size(); ++i)
        if (A[i] != 0)
        {
            B.emplace(std::make_pair(i, A[i]));
        }
    return B;
}


/**
 * @brief      Convert a sparse vector into its condensed representation.
 *
 * @param[in]  A     A sparse vector.
 *
 * @return     A reduced-size sparse vector.
 */
vector<int> condensify(const vector<int> &A)
{
    vector<int> B(A.size() * 2);
    int k = 0;
    for (auto i = 0; i < A.size(); ++i)
    {
        if (A[i] != 0)
        {
            B[k] = i;
            B[k+1] = A[i];
            k += 2;
        }
    }
    B.resize(k);
    return B;
}



long dotProduct(const vector<int> &A, const vector<int> &B)
{
    long res = 0;
    for (auto i = 0; i < A.size(); ++i)
    {
        res += A[i] * B[i];
    }
    return res;
}


long dotProduct(const unordered_map<int, int> &A, const unordered_map<int, int> &B)
{
    long res = 0;
    for (auto const &a: A)
    {
        auto b = B.find(a.first);
        if (b != B.end())
        {
            res += b->second * a.second;
        }
    }
    return res;
}


long dotProduct(const unordered_map<int, int> &A, const vector<int> &B)
{
    long res = 0;
    for (auto const &a: A)
    {
        res += B[a.first] * a.second;
    }
    return res;
}


// First vector must use sparse representation.
long dotProductCondSparse(const vector<int> &A, const vector<int> &B)
{
    long res = 0;
    for (auto k = 0; k < A.size(); k += 2)
    {
        res += B[A[k]] * A[k+1];
    }
    return res;
}


long dotProductSparse(const vector<int> &A, const vector<int> &B)
{
    long res = 0;
    auto a = A.begin();
    auto b = B.begin();
    auto a_end = A.end();
    auto b_end = B.end();
    if (b == b_end)
      return 0l;

    while (a != a_end)
    {
        while (b != b_end && *b < *a)
        {
          b += 2;
        }
        if (b == b_end)
          break;

        if (*b == *a)
        {
          res += *(b+1) * *(a+1);
          a += 2;
        }
        else
        {
          swap(a, b);
          swap(a_end, b_end);
        }
    }
    return res;
}
