#ifndef DARRAY_H
#define DARRAY_H

#include <array>
#include <math.h>
#include <string>

using namespace std;

typedef const size_t csize;

template<csize d>
struct darray {
    array<double, d> components;
    double magnitude;
    int assignment;
    darray(const array<double, d> components) : components(components), magnitude(-1), assignment(-1)
    {
        computeMagnitude();
    }
    void computeMagnitude()
    {
        double sum = 0;
        for (int i = 0; i < d; i++)
        {
            sum += components[i];
        }
        magnitude = sqrt(sum);
    }
    double &operator[](const int i)
    {
        return components[i];
    }
};

template<csize d>
double darrayDistance(const darray<d> &a, const darray<d> &b);

template<csize d>
double darrayLowerBound(const darray<d> &a, const darray<d> &b);

template<csize d>
double darrayUpperBound(const darray<d> &a, const darray<d> &b);

template<csize d>
string toPrettyString(const darray<d> &a);

#endif /* DARRAY_H */

