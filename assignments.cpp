#include "assignments.h"

template<csize d>
void assign(vector<darray<d>> &vectors, const vector<darray<d>> &clusters)
{
    for (int i = 0; i < vectors.size(); i++)
    {
        double minDist = MAX;
        for (int j = 0; j < clusters.size(); j++)
        {
            const double dist = darrayDistance(vectors[i], clusters[j]);
            if (minDist > dist)
            {
                minDist = dist;
                vectors[i].assignment = j;
            }
        }
    }
}

template<csize d>
void optimizedAssign(vector<darray<d>> &vectors, const vector<darray<d>> &clusters)
{
    for (int i = 0; i < vectors.size(); i++)
    {
        double minDist = MAX;
        for (int j = 0; j < clusters.size(); j++)
        {
            const double lbDist = darrayLowerBound<d>(vectors[i], clusters[j]);
            if (minDist > lbDist)
            {
                const double dist = darrayDistance<d>(vectors[i], clusters[j]);
                if (minDist > dist)
                {
                    minDist = dist;
                    vectors[i].assignment = j;
                }
            }
        }
    }
}

template<csize d>
void update(vector<darray<d>> &clusters, const vector<darray<d>> &vectors)
{
    for (int i = 0; i < clusters.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < d; j++)
        {
            clusters[i][j] = 0;
        }
        for (int j = 0; j < vectors.size(); j++)
        {
            if (i == vectors[j].assignment)
            {
                for (int k = 0; k < d; k++)
                {
                    clusters[i][k] += vectors[j][k];
                }
                count++;
            }
        }
        for (int j = 0; j < d; j++)
        {
            clusters[i][j] /= count;
        }
        clusters[i].computeMagnitude();
    }
}
