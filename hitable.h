// -*- mode: c++ -*-
#ifndef HITABLE_H
#define HITABLE_H

#include "vec3.h"


struct record {
    vec3 p;
    vec3 normal;
    double t;
    bool front_face;
};

struct hitable {
    hitable() = default;
    virtual ~hitable() = default;
    virtual bool hit(const ray& r, double tmin, double tmax, record& rec) const = 0;
};

#endif /* HITABLE_H */
