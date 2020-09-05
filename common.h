// -*- mode: c++ -*-
#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>


inline
double randf()
{
    return rand() / (RAND_MAX + 1.0);
}

inline
double randf(double min, double max)
{
    return min + (max - min) * randf();
}

inline
double clamp(double x, double min, double max)
{
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

#endif /* COMMON_H */
