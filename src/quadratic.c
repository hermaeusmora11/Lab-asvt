#include "quadratic.h"
#include <math.h>

int solve_quadratic(double a, double b, double c, double roots[2]) {
    const double EPS = 1e-7;

    if (fabs(a) < EPS) {
        return -1;
    }

    double d = b * b - 4 * a * c;

    if (fabs(d) < EPS) {
        roots[0] = -b / (2 * a);
        return 1;
    }

    if (d < 0) {
        return 0;
    }

    double sqrt_d = sqrt(d);

    roots[0] = (-b - sqrt_d) / (2 * a);
    roots[1] = (-b + sqrt_d) / (2 * a);

    return 2;
}
