#include <stdio.h>

int gcd(int,int);

int gcd(int u, int v) {
    int t;
    do {
        if (u < v) {
            t = u;
            u = v;
            v = t;
        }
        /* printf("u = %d, v = %d\n",u,v); */
        u = u - v;
    } while (u > 0);
    return v;
}

void main() {
    int u,v;
    printf("max int = %d", __INT_MAX__);
    while (1) {
        printf("enter u v: ");
        scanf("%d %d",&u,&v);
        if (u < 0 || v < 0) break;
        printf("u=%d v=%d gcd=%d\n",u,v,gcd(u,v));
    }
}
