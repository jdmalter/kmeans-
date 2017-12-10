#ifndef DARRAY_H
#define DARRAY_H

#include <array>
#include <string>

using namespace std;

typedef const size_t csize;

template<csize d>
using darray = array<double, d>;

template<csize d>
double darrayDistance(const darray<d> &a, const darray<d> &b);

template<csize d>
string toPrettyString(const darray<d> &a);

#endif /* DARRAY_H */

