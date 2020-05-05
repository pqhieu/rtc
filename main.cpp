#include <stdio.h>

#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include "hitlist.h"


vec3 ray_color(const ray& r, const hitable& world)
{
    record rec;
    if (world.hit(r, 0.0, 1e10, rec)) {
        return 0.5 * (rec.normal + 1.0);
    }
    vec3 dir = normalize(r.dir);
    double t = 0.5 * (dir.y + 1.0);
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}


int main()
{
    const int width  = 200;
    const int height = 100;

    vec3 lower_left(-2.0, -1.0, -1.0);
    vec3 horizontal(+4.0, +0.0, +0.0);
    vec3 vertical(+0.0, +2.0, +0.0);
    vec3 origin(+0.0, +0.0, +0.0);

    hitlist world;
    world.add(std::make_shared<sphere>(vec3(0.0, 0.0, -1.0), 0.5));
    world.add(std::make_shared<sphere>(vec3(0.0, -100.5, -1.0), 100.0));

    fprintf(stdout, "P3\n%d %d\n255\n", width, height);
    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            double u = (double)x / width;
            double v = (double)y / height;
            ray r(origin, lower_left + u * horizontal + v * vertical);
            vec3 color = ray_color(r, world);
            int ir = (int)(255.999 * color.r);
            int ig = (int)(255.999 * color.g);
            int ib = (int)(255.999 * color.b);
            fprintf(stdout, "%d %d %d\n", ir, ig, ib);
        }
    }
}
