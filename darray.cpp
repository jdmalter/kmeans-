#include "darray.h"

template<csize d>
double darrayDistance(const darray<d> &a, const darray<d> &b)
{
    double sum = 0;
    for (int i = 0; i < d; i++)
    {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

template<csize d>
double darrayLowerBound(const darray<d> &a, const darray<d> &b)
{
    return abs(a.magnitude - b.magnitude);
}

template<csize d>
double darrayUpperBound(const darray<d> &a, const darray<d> &b)
{
    return a.magnitude + b.magnitude;
}

template<csize d>
string toPrettyString(const darray<d> &a)
{
    string sum;
    if (0 < d)
    {
        sum += to_string(a[0]);
        sum.erase(sum.find_last_not_of('0') + 1, string::npos);
        if (sum.back() == '.')
        {
            sum.pop_back();
        }
    }
    for (int i = 1; i < d; i++)
    {
        sum += ", ";
        sum += to_string(a[i]);
        sum.erase(sum.find_last_not_of('0') + 1, string::npos);
        if (sum.back() == '.')
        {
            sum.pop_back();
        }
    }
    return "[" + sum + "]";
}
