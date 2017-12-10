#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <limits>
#include <vector>
#include "darray.cpp"

static constexpr double MAX = numeric_limits<double>::max();

template<csize d>
void assign(vector<darray<d>> &vectors, const vector<darray<d>> &clusters);

template<csize d>
void update(vector<darray<d>> &clusters, const vector<darray<d>> &vectors);

#endif /* ASSIGNMENTS_H */

