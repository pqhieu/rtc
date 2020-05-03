// -*- mode: c++ -*-
#ifndef RAY_H
#define RAY_H

#include "vec3.h"

struct ray {
    vec3 origin;
    vec3 dir;

    ray(const vec3& origin, const vec3& dir): origin(origin), dir(dir) {}

    vec3 at(double t) const;
};

inline
vec3 ray::at(double t) const
{
    return origin + dir * t;
}

#endif /* RAY_H */
