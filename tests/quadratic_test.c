#include "quadratic.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

int main() {
    double roots[2];
    int count;

    count = solve_quadratic(0, 1, 1, roots);
    assert(count == -1);

    count = solve_quadratic(1, 0, -1, roots);
    assert(count == 2);
    assert(fabs(roots[0] + 1) < 1e-7);
    assert(fabs(roots[1] - 1) < 1e-7);

    count = solve_quadratic(1, 0, 0, roots);
    assert(count == 1);
    assert(fabs(roots[0]) < 1e-7);

    count = solve_quadratic(1, 0, 1, roots);
    assert(count == 0);

    count = solve_quadratic(1, 0, -1e-7, roots);
    assert(count == 2);
    assert(fabs(roots[0] + 3e-4) < 1e-4);
    assert(fabs(roots[1] - 3e-4) < 1e-4);

    count = solve_quadratic(1, -1e10, -1, roots);
    assert(count == 2);
    assert(fabs(roots[0] + 1e-10) < 1e-11);
    assert(fabs(roots[1] - 1e10) < 1e-1);

    count = solve_quadratic(1, 0, -1e-8, roots);
    if (count == 1) {
        assert(fabs(roots[0]) < 1e-7);
    } else {
        assert(count == 2);
    }

    printf("Task 4 OK\n");
    return 0;
}
