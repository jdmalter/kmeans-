#ifndef DARRAY_H
#define DARRAY_H

#include <string>

using namespace std;

typedef const size_t csize;
typedef const double* darray;

double distance(csize d, darray a, darray b);

string toPrettyString(csize d, darray a);

#endif /* DARRAY_H */

