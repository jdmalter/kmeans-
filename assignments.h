#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <limits>
#include <vector>
#include "darray.h"

static constexpr double MAX = numeric_limits<double>::max();

void assign(csize d, 
        vector<int> &assignments, 
        const vector<darray> &vectors, 
        const vector<double*> &clusters);

void update(csize d, 
        vector<double*> &clusters, 
        const vector<darray> &vectors, 
        const vector<int> &assignments);

#endif /* ASSIGNMENTS_H */

