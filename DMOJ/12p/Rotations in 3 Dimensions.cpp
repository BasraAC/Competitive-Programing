/*
problem: https://dmoj.ca/problem/3drotate
solution: https://dmoj.ca/submission/6758986
*/

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#pragma GCC optimize("Ofast,branch-probabilities,unroll-loops,peel-loops,tracer,vpt,inline-functions,ipa-cp,ipa-cp-clone,ipa-bit-cp,predictive-commoning,split-loops,unswitch-loops,gcse-after-reload,tree-loop-vectorize,tree-slp-vectorize,vect-cost-model=dynamic,tree-loop-distribute-patterns,fast-math,no-math-errno,strict-aliasing,prefetch-loop-arrays,funroll-all-loops")
#pragma GCC target("sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native,avx2")


extern int getchar_unlocked(void);

// Function to read a double from input
static inline double read_double() {
    double num = 0.0;
    int neg = 0;  
    char c = getchar_unlocked();
    
    while (c <= 32) c = getchar_unlocked();

    if (c == '-') {
        neg = 1;
        c = getchar_unlocked();
    }

    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar_unlocked();
    }

    if (c == '.') {
        double frac = 0.1;  
        c = getchar_unlocked();
        while (c >= '0' && c <= '9') {
            num += (c - '0') * frac;
            frac /= 10;  
            c = getchar_unlocked();
        }
    }

    return neg ? -num : num;
}

//quake three hack???
double invSqrt(double x) {
    const double threehalfs = 1.5;

    double x2 = x * 0.5;
    double y = x;

   
    int64_t i;
    memcpy(&i, &y, sizeof(i)); 
    i = 0x5fe6ec85e7de30da - (i >> 1);  
    memcpy(&y, &i, sizeof(y));  


    y = y * (threehalfs - (x2 * y * y));
    y = y * (threehalfs - (x2 * y * y));
    y = y * (threehalfs - (x2 * y * y));

    return y;  
}


int main() {
    int t;
    
    scanf("%d", &t); 

    while (t--) {
        double x, y, z, rx, ry, rz, radians;

        x = read_double();
        y = read_double();
        z = read_double();
        rx = read_double();
        ry = read_double();
        rz = read_double();
        radians = read_double();

        double mag = invSqrt(rx * rx + ry * ry + rz * rz);
        rx *= mag; ry *= mag; rz *= mag;

        double c = cos(radians), s = sin(radians);

        printf("%lf %lf %lf\n", 
            c * x + s * (ry * z - rz * y) + (1 - c) * (rx * x + ry * y + rz * z) * rx, 
            c * y + s * (rz * x - rx * z) + (1 - c) * (rx * x + ry * y + rz * z) * ry, 
            c * z + s * (rx * y - ry * x) + (1 - c) * (rx * x + ry * y + rz * z) * rz);
    }

    return 0;
}