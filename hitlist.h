// -*- mode: c++ -*-
#ifndef HITLIST_H
#define HITLIST_H

#include <memory>
#include <vector>
#include "hitable.h"


struct hitlist: public hitable {
    std::vector<std::shared_ptr<hitable>> list;

    hitlist() = default;
    virtual ~hitlist() = default;

    void clear() { list.clear(); }
    void add(std::shared_ptr<hitable> o) { list.push_back(o); }

    virtual bool hit(const ray& r, double tmin, double tmax, record& rec) const;
};

inline
bool hitlist::hit(const ray& r, double tmin, double tmax, record& rec) const
{
    record hit;
    bool hit_anything = false;
    for (const auto& o : list) {
        if (o->hit(r, tmin, tmax, hit)) {
            hit_anything = true;
            tmax = hit.t;
            rec = hit;
        }
    }
    return hit_anything;
}

#endif /* HITLIST_H */
