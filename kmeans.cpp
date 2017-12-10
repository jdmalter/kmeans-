#include "kmeans.h"

template<csize d>
vector<darray<d>> takeRandom(const vector<darray<d>> &vectors, csize k)
{
    vector<darray<d>> clusters;
    for (int i = 0; i < k; i++)
    {
        array<double, d>* components = new array<double, d>;
        int random = rand() % vectors.size();
        for (int j = 0; j < d; j++)
        {
            (*components)[j] = vectors[random][j];
        }
        darray<d>* pointer = new darray<d>(*components);
        clusters.push_back(*pointer);
    }
    return clusters;
}

template<csize d>
vector<darray<d>> run(vector<darray<d>> &vectors, csize k, cu32 iterations)
{
    vector<darray<d>> clusters = takeRandom<d>(vectors, k);
    for (int i = 0; i < iterations; i++)
    {
        optimzedAssign<d>(vectors, clusters);
        update<d>(clusters, vectors);
    }
    return clusters;
}
