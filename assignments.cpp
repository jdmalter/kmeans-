#include "assignments.h"

template<csize d>
void assign(vector<int> &assignments, 
        const vector<darray<d>> &vectors, 
        const vector<darray<d>> &clusters)
{
    for (int i = 0; i < vectors.size(); i++)
    {
        double min = MAX;
        for (int j = 0; j < clusters.size(); j++)
        {
            double dis = distance<d>(vectors[i], clusters[j]);
            if (min > dis)
            {
                min = dis;
                assignments[i] = j;
            }
        }
    }
}

template<csize d>
void update(vector<darray<d>> &clusters, 
        const vector<darray<d>> &vectors, 
        const vector<int> &assignments)
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
            if (i == assignments[j])
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
    }
}
