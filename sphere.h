// -*- mode: c++ -*-
#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"


struct sphere {
    vec3 center;
    double radius;

    sphere() = default;

    sphere(const vec3& center, double radius) : center(center), radius(radius) {}

    bool hit(const ray& r) const;
};

inline
bool sphere::hit(const ray& r) const
{
    vec3 oc = r.origin - center;
    double a = dot(r.dir, r.dir);
    double b = dot(r.dir, oc);
    double c = dot(oc, oc) - radius * radius;
    double discriminant = b * b - a * c;
    return (discriminant > 0.0);
}

#endif /* SPHERE_H */
