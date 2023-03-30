#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define base_type float
#define fmt_str "%.3f"

typedef struct vec2 {
    base_type x;
    base_type y;
} vec2;

typedef struct vec3 {
    base_type x;
    base_type y;
    base_type z;
} vec3;

vec2 add2(vec2 a, vec2 b) {
    return (vec2) {
        .x = a.x + b.x,
        .y = a.y + b.y
    };
}

vec3 add3(vec3 a, vec3 b) {
    return (vec3) {
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z
    };
}

vec2 sub2(vec2 a, vec2 b) {
    return (vec2) {
        .x = a.x - b.x,
        .y = a.y - b.y
    };
}

vec3 sub3(vec3 a, vec3 b) {
    return (vec3) {
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z
    };
}

base_type dot2(vec2 a, vec2 b) {
    return a.x * b.x + b.y * b.y;
}

base_type dot3(vec3 a, vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// | a.x b.x |
// | a.y b.y |
base_type det2(vec2 a, vec2 b) {
    return a.x * b.y - a.y * b.x;
}

// | a.x b.x c.x |
// | a.y b.y c.y |
// | a.z b.z c.z |
base_type det3(vec3 a, vec3 b, vec3 c) {
    return a.x * b.y * c.z + b.x * c.y * a.z + c.x * a.y * b.z
        - (c.x * b.y * a.z + b.x * a.y * c.z + a.x * c.y * b.z);
}

vec3 cross3(vec3 a, vec3 b) {
    return (vec3) {
        .x = a.y * b.z - a.z * b.y,
        .y = a.z * b.x - a.x * b.z,
        .z = a.x * b.y - a.y * b.x
    };
}

vec2 v2(base_type x, base_type y) {
    return (vec2) { .x = x, .y = y };
}

vec3 v3(base_type x, base_type y, base_type z) {
    return (vec3) { .x = x, .y = y, .z = z };
}

void print3(vec3 v) {
    printf("(" fmt_str ", " fmt_str ", " fmt_str ")\n", v.x, v.y, v.z);
}

void print2(vec2 v) {
    printf("(" fmt_str ", " fmt_str ")\n", v.x, v.y);
}

vec3 read3() {
    vec3 v;

    assert(scanf("(" fmt_str ", " fmt_str ", " fmt_str ")\n", &v.x, &v.y, &v.z) == 3);

    return v;
}

vec2 read2() {
    vec2 v;

    int result = scanf("(" fmt_str ", " fmt_str ")\n", &v.x, &v.y);
    assert(result == 2);

    return v;
}

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
