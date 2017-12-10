#ifndef KMEANS_H
#define KMEANS_H

#include <vector>
#include "assignments.cpp"

typedef const unsigned int cu32;

template<csize d>
struct AssignmentsClusters
{
    const vector<int> assignments;
    const vector<darray<d>> clusters;
};

template<csize d>
AssignmentsClusters<d> run(const vector<darray<d>> &vectors, csize k, cu32 iterations);

#endif /* KMEANS_H */

