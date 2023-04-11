#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <math.h>

#include "util.h"

#define N 1024

typedef struct polygon {
    int n;
    vec2 vertices[N];
} polygon;

void addVertex(polygon* p, vec2 v) {
    p->vertices[p->n++] = v;
}

vec2 intersect(vec2 a1, vec2 a2, vec2 b1 , vec2 b2) {
    vec2 t;

    base_type den = (a1.x - a2.x) * (b1.y - b2.y) - (a1.y - a2.y) * (b1.x - b2.x);

    if (den == 0)
        return v2(-1, -1);

    t.x = (a1.x - b1.x) * (b1.y - b2.y) - (a1.y - b1.y) * (b1.x - b2.x);
    t.y = (a1.x - b1.x) * (a1.y - a2.y) - (a1.y - b1.y) * (a1.x - a2.x);

    t.x /= den;
    t.y /= den;

    return t;
}

int main() {
    int n, m;
    assert(scanf("%d %d", &m, &n) == 2); 

    polygon *poligonos = calloc(n, sizeof(polygon));

    for (int i = 0; i < m; i++) {
        int num_vertices;
        assert(scanf("%d", &num_vertices) == 1);

        for (int j = 0; j < num_vertices; j++) {
            vec2 v = read2();
            addVertex(&poligonos[i], v);
        }
    }

    for (int i = 0; i < m; i++) {
        vec2 vprev, v, vnext;
        int convex = 1;
        vprev = poligonos[i].vertices[0];
        v     = poligonos[i].vertices[1];
        vnext = poligonos[i].vertices[2];

        base_type det = det2(sub2(v, vprev), sub2(vnext, v));
        int prev_sign = (det > 0) - (det < 0);

        // teste convexidade
        for (int j = 0; j < poligonos[i].n; j++) {
            vprev = poligonos[i].vertices[(j + 0) % poligonos[i].n];
            v     = poligonos[i].vertices[(j + 1) % poligonos[i].n];
            vnext = poligonos[i].vertices[(j + 2) % poligonos[i].n];

            base_type det = det2(sub2(v, vprev), sub2(vnext, v));

            int sign = (det > 0) - (det < 0);

            if (sign != prev_sign) {
                convex = 0;
                break;
            }
        }

        int simple = 1;

        // teste simplicidade (?)
        for (int j = 0; j < poligonos[i].n; j++) {
            vec2 a1 = poligonos[i].vertices[j];
            vec2 a2 = poligonos[i].vertices[(j + 1) % poligonos[i].n];
            for (int k = 0; k < poligonos[i].n; k++) {
                vec2 b1 = poligonos[i].vertices[k];
                vec2 b2 = poligonos[i].vertices[(k + 1) % poligonos[i].n];

                vec2 intersection = intersect(a1, a2, b1, b2);

                if (intersection.x > 0 && intersection.x < 1 &&
                    intersection.y > 0 && intersection.y < 1) {
                    simple = 0;
                }
            }
        }

        printf("%d é %s e %sconvexo\n", i, simple ? "simples" : "nao simples", convex ? "" : "nao ");
    }


    vec2 *pontos = calloc(n, sizeof(vec2));
    for (int i = 0; i < n; i++) {
        pontos[i] = read2();
    }

    for (int i = 0; i < m; i++) {
        printf("%d:", i + 1);

        for (int j = 0; j < n; j++) {
            int intersections = 0;

            for (int k = 0; k < poligonos[i].n; k++) {
                vec2 t = intersect(pontos[j],
                                   add2(pontos[j], v2(0, 1)),
                                   poligonos[i].vertices[k],
                                   poligonos[i].vertices[(k + 1) % poligonos[i].n]);

                if (t.x > 0 && t.y > 0 && t.y < 1)
                    intersections++;

            }

            if (intersections % 2 == 1)
                printf("%d ", j + 1);
        }

        printf("\n");
    }

    free(poligonos);
    return 0;
}
