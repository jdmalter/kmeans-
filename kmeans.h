#ifndef KMEANS_H
#define KMEANS_H

#include "assignments.h"

struct AssignmentsClusters
{
    const vector<int> assignments;
    const vector<double*> clusters;
};

AssignmentsClusters run(csize d, const vector<darray> &vectors, csize k);

#endif /* KMEANS_H */

