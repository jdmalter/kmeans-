#include "kmeans.h"

template<csize d>
vector<darray<d>> takeRandom(const vector<darray<d>> &vectors, csize k)
{
    vector<darray<d>> clusters;
    for (int i = 0; i < k; i++)
    {
        darray<d>* pointer = new darray<d>;
        int random = rand() % vectors.size();
        for (int j = 0; j < d; j++)
        {
            (*pointer)[j] = vectors[random][j];
        }
        clusters.push_back(*pointer);
    }
    return clusters;
}

template<csize d>
AssignmentsClusters<d> run(const vector<darray<d>> &vectors, csize k, cu32 iterations)
{
    vector<darray<d>> clusters = takeRandom<d>(vectors, k);
    vector<int> assignments(vectors.size());
    for (int i = 0; i < iterations; i++)
    {
        assign<d>(assignments, vectors, clusters);
        update<d>(clusters, vectors, assignments);
    }
    return AssignmentsClusters<d>{assignments, clusters};
}
