#include <stdio.h>

#include "vec3.h"
#include "ray.h"


int main()
{
    const int width  = 200;
    const int height = 100;
    fprintf(stdout, "P3\n%d %d\n255\n", width, height);
    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            double r = (double)x / width;
            double g = (double)y / height;
            double b = 0.2;
            int ir = (int)(255.999 * r);
            int ig = (int)(255.999 * g);
            int ib = (int)(255.999 * b);
            fprintf(stdout, "%d %d %d\n", ir, ig, ib);
        }
    }
}
