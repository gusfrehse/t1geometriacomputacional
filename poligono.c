#include <stdio.h>

#define base_type float
#define fmt_str "% .3f"

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

vec2 add3(vec3 a, vec3 b) {
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

vec2 sub3(vec3 a, vec3 b) {
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

base_type cross2(vec2 a, vec2 b) {
    return a.x * b.y - a.y * b.x;
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
    v3 v;

    scanf("(" fmt_str ", " fmt_str ", " fmt_str ")\n", &v.x, &v.y, &v.z);

    return v;
}

vec2 read2() {
    v2 v;

    scanf("(" fmt_str ", " fmt_str ")\n", &v.x, &v.y);

    return v;
}

#define N 1024

typedef struct polygon {
    int n;
    v2 vertices[N];
} polygon;

void addVertex(polygon* p, v2 v) {
    p.vertices[p.n++] = v;
}

int main() {
3
    scanf("%d %d", &n, &m); 

    polygon poligonos[] = calloc(n, sizeof(polygon));

    for (int i = 0; i < n; i++) {
        int num_vertices;
        scanf("%d", &num_vertices);

        int convexo = 0;
        v2 vprev = read2(), v;
        addVertex(&poligonos[j], vprev);

        for (int j = 0; j < num_vertices; j++) {
            v = read2();
            addVertex(&poligonos[j], v);

            if (cross
        }
        

        poligonos[j].vertice
        
    }

    return 0;
}
