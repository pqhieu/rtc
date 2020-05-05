// -*- mode: c++ -*-
#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "hitable.h"


struct sphere: public hitable {
    vec3 center;
    double radius;

    sphere() = default;
    sphere(const vec3& center, double radius) : center(center), radius(radius) {}
    virtual ~sphere() = default;

    virtual bool hit(const ray& r, double tmin, double tmax, record& rec) const;
};

inline
bool sphere::hit(const ray& r, double tmin, double tmax, record& rec) const
{
    vec3 oc = r.origin - center;
    double a = dot(r.dir, r.dir);
    double b = dot(r.dir, oc);
    double c = dot(oc, oc) - radius * radius;
    double discriminant = b * b - a * c;
    if (discriminant > 0.0) {
        double root = sqrt(discriminant);
        double t = (-b - root) / a;
        if ((t < tmax) && (t > tmin)) {
            rec.t = t;
            rec.p = r.at(t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
        t = (-b + root) / a;
        if ((t < tmax) && (t > tmin)) {
            rec.t = t;
            rec.p = r.at(t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
    }
    return false;
}

#endif /* SPHERE_H */
