// -*- mode: c++ -*-
#ifndef VEC3_H
#define VEC3_H

#include <math.h>


struct vec3 {
    union {
        double data[3];
        struct {
            double x;
            double y;
            double z;
        };
    };
};


inline
vec3 operator+(const vec3& a, const vec3& b)
{
    vec3 r;
    r.data[0] = a.data[0] + b.data[0];
    r.data[1] = a.data[1] + b.data[1];
    r.data[2] = a.data[2] + b.data[2];
    return r;
}

inline
vec3 operator-(const vec3& a, const vec3& b)
{
    vec3 r;
    r.data[0] = a.data[0] - b.data[0];
    r.data[1] = a.data[1] - b.data[1];
    r.data[2] = a.data[2] - b.data[2];
    return r;
}

inline
vec3 operator*(const vec3& a, const vec3& b)
{
    vec3 r;
    r.data[0] = a.data[0] * b.data[0];
    r.data[1] = a.data[1] * b.data[1];
    r.data[2] = a.data[2] * b.data[2];
    return r;
}

inline
vec3 operator/(const vec3& a, const vec3& b)
{
    vec3 r;
    r.data[0] = a.data[0] / b.data[0];
    r.data[1] = a.data[1] / b.data[1];
    r.data[2] = a.data[2] / b.data[2];
    return r;
}

inline
double dot(const vec3& a, const vec3& b)
{
    double xx = a.data[0] * b.data[0];
    double yy = a.data[1] * b.data[1];
    double zz = a.data[2] * b.data[2];
    return xx + yy + zz;
}

inline
double norm2(const vec3& v)
{
    return dot(v, v);
}

inline
double norm(const vec3& v)
{
    return sqrt(norm2(v));
}

#endif /* VEC3_H */
