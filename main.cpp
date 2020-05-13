#include <stdio.h>

#include "camera.h"
#include "common.h"
#include "hitlist.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"


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
    const double aspect_ratio = 16.0 / 9.0;
    const int width  = 384;
    const int height = (int)(width / aspect_ratio);
    const int num_samples_per_pixel = 100;

    camera cam;
    hitlist world;
    world.add(std::make_shared<sphere>(vec3(0.0, 0.0, -1.0), 0.5));
    world.add(std::make_shared<sphere>(vec3(0.0, -100.5, -1.0), 100.0));

    fprintf(stdout, "P3\n%d %d\n255\n", width, height);
    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            vec3 color(0.0, 0.0, 0.0);
            for (int s = 0; s < num_samples_per_pixel; ++s) {
                double u = (x + randf()) / (width  - 1);
                double v = (y + randf()) / (height - 1);
                ray r = cam.get_ray(u, v);
                color = color + ray_color(r, world);
            }
            color.r = color.r / num_samples_per_pixel;
            color.g = color.g / num_samples_per_pixel;
            color.b = color.b / num_samples_per_pixel;
            int ir = (int)(256 * clamp(color.r, 0.0, 0.999));
            int ig = (int)(256 * clamp(color.g, 0.0, 0.999));
            int ib = (int)(256 * clamp(color.b, 0.0, 0.999));
            fprintf(stdout, "%d %d %d\n", ir, ig, ib);
        }
    }
}
