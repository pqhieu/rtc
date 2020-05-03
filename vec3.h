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
        struct {
            double r;
            double g;
            double b;
        };
    };

    vec3() = default;

    vec3(double v) {
        data[0] = v;
        data[1] = v;
        data[2] = v;
    }

    vec3(double x, double y, double z) {
        data[0] = x;
        data[1] = y;
        data[2] = z;
    }
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
vec3 operator*(const vec3& v, double s)
{
    vec3 r;
    r.data[0] = v.data[0] * s;
    r.data[1] = v.data[1] * s;
    r.data[2] = v.data[2] * s;
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

inline
vec3 normalize(const vec3& v)
{
    double n = norm(v);
    if (n == 0.0) {
        return vec3(0.0);
    } else {
        return v / n;
    }
}

#endif /* VEC3_H */
