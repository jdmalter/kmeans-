#include <math.h>
#include "darray.h"

double distance(csize d, darray a, darray b)
{
    double sum = 0;
    for (int i = 0; i < d; i++)
    {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

string toPrettyString(csize d, darray a)
{
    string sum;
    if (0 < d)
    {
        sum += std::to_string(a[0]);
    }
    for (int i = 1; i < d; i++)
    {
        sum += ", ";
        sum += std::to_string(a[i]);
    }
    return "[" + sum + "]";
}
