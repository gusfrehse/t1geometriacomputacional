#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "util.h"

#define N 1024

typedef struct polygon {
    int n;
    vec2 vertices[N];
} polygon;

void addVertex(polygon* p, vec2 v) {
    p->vertices[p->n++] = v;
}

int main() {
    int n, m;
    assert(scanf("%d %d", &n, &m) == 2); 

    polygon *poligonos = calloc(n, sizeof(polygon));

    for (int i = 0; i < n; i++) {
        int num_vertices;
        assert(scanf("%d", &num_vertices) == 1);

        for (int j = 0; j < num_vertices; j++) {
            vec2 v = read2();
            addVertex(&poligonos[i], v);
        }
    }

    for (int i = 0; i < n; i++) {
        vec2 vprev, v, vnext;
        int convex = 1;
        vprev = poligonos[i].vertices[0];
        v     = poligonos[i].vertices[1];
        vnext = poligonos[i].vertices[2];

        int det = det2(sub2(v, vprev), sub2(vnext, v));
        printf("% .3f det\n", det);
        int prev_sign = (det > 0) - (det < 0);

        for (int j = 0; j < poligonos[i].n; j++) {
            vprev = poligonos[i].vertices[(j + 0) % n];
            v     = poligonos[i].vertices[(j + 1) % n];
            vnext = poligonos[i].vertices[(j + 2) % n];

            int det = det2(sub2(v, vprev), sub2(vnext, v));
            printf("% .3f det\n", det);
            int sign = (det > 0) - (det < 0);

            if (sign != prev_sign) {
                convex = 0;
                break;
            }
        }

        printf("%d %sconvexo\n", i, convex ? "" : "nao ");
    }

    return 0;
}
