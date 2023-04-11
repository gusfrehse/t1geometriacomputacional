#include "util.h"

#include <stdio.h>
#include <assert.h>

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
    printf("(" out_fmt_str ", " out_fmt_str ", " out_fmt_str ")\n", v.x, v.y, v.z);
}

void print2(vec2 v) {
    printf("(" out_fmt_str ", " out_fmt_str ")\n", v.x, v.y);
}

vec3 read3() {
    vec3 v;

    assert(scanf(in_fmt_str " " in_fmt_str " " in_fmt_str, &v.x, &v.y, &v.z) == 3);

    return v;
}

vec2 read2() {
    vec2 v;

    int result = scanf(" " in_fmt_str " " in_fmt_str " ", &v.x, &v.y);
    assert(result == 2);

    return v;
}
