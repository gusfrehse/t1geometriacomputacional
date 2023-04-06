#ifndef UTIL_H
#define UTIL_H

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

vec2 add2(vec2 a, vec2 b);

vec3 add3(vec3 a, vec3 b);

vec2 sub2(vec2 a, vec2 b);

vec3 sub3(vec3 a, vec3 b);

base_type dot2(vec2 a, vec2 b);

base_type dot3(vec3 a, vec3 b);

// | a.x b.x |
// | a.y b.y |
base_type det2(vec2 a, vec2 b);

// | a.x b.x c.x |
// | a.y b.y c.y |
// | a.z b.z c.z |
base_type det3(vec3 a, vec3 b, vec3 c);

vec3 cross3(vec3 a, vec3 b);

vec2 v2(base_type x, base_type y);

vec3 v3(base_type x, base_type y, base_type z);

void print3(vec3 v);

void print2(vec2 v);

vec3 read3();

vec2 read2();

#endif
