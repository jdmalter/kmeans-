#include "kmeans.h"

vector<double*> takeRandom(csize d, const vector<darray> &vectors, csize k)
{
    vector<double*> clusters;
    for (int i = 0; i < k; i++)
    {
        double* cluster = (double*)malloc(d * sizeof(double));
        int random = rand() % vectors.size();
        for (int j = 0; j < d; j++)
        {
            cluster[j] = vectors[random][j];
        }
        clusters.push_back(cluster);
    }
    return clusters;
}

AssignmentsClusters run(csize d, const vector<darray> &vectors, csize k)
{
    vector<double*> clusters = takeRandom(d, vectors, k);
    vector<int> assignments(vectors.size());
    for (int i = 0; i < 50; i++)
    {
        assign(d, assignments, vectors, clusters);
        update(d, clusters, vectors, assignments);
    }
    return AssignmentsClusters{assignments, clusters};
}
