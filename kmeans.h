#ifndef KMEANS_H
#define KMEANS_H

#include <vector>
#include "assignments.cpp"

typedef const unsigned int cu32;

template<csize d>
vector<darray<d>> run(vector<darray<d>> &vectors, csize k, cu32 iterations);

#endif /* KMEANS_H */

