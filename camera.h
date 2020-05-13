// -*- mode: c++ -*-
#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include "vec3.h"


struct camera {
    vec3 origin;
    vec3 lower_left;
    vec3 horizontal;
    vec3 vertical;

    camera() {
        origin     = vec3(+0.0, +0.0, +0.0);
        lower_left = vec3(-2.0, -1.0, -1.0);
        horizontal = vec3(+4.0, +0.0, +0.0);
        vertical   = vec3(+0.0, +2.0, +0.0);
    }

    ray get_ray(double u, double v) const {
        return ray(origin, lower_left + u * horizontal + v * vertical - origin);
    }
};

#endif /* CAMERA_H */
