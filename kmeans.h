#ifndef KMEANS_H
#define KMEANS_H

#include <vector>
#include "assignments.h"

template<csize d>
struct AssignmentsClusters
{
    const vector<int> assignments;
    const vector<darray<d>> clusters;
};

template<csize d>
AssignmentsClusters<d> run(const vector<darray<d>> &vectors, csize k);

#endif /* KMEANS_H */

