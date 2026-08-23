#include <stdlib.h>
#include <stdio.h>

/*
 * unionfind.c
 *
 * A union-find data structure that assigns each connected location to a
 * unique segment and supports O(1) connectivity queries.
 *
 * From Robert Sedgewick, "Algorithms in C" (1990).
 *
 * Example graph:
 *
 *        6
 *        |
 *    1 - 2 - 3  7 - 8
 *        |   |
 *        4 - 5
 *
 */

int main(void);
int isConnected(int p, int q);
int find(int p);
void unionfind(int p, int q);

int edges[] = {1,2,2,4,2,6,2,3,4,5,3,5,7,8};
int edge_count = 7;

// Size of each segment, indexed by location.
int siz[] = {0,1,1,1,1,1,1,1,1};
// Parent pointer for each location; each root identifies its segment.
int sid[] = {0,1,2,3,4,5,6,7,8};
int segment_count = 8;

int main(void) {
    // Process each edge and merge any connected components.
    for (int i=0; i < edge_count * 2; i += 2) {
        unionfind(edges[i],edges[i+1]);
    }

    // Show the final segment sizes and representative ids.
    printf("Segments = %d\n",segment_count);
    for (int i=1;i<=8;i++) {
        printf("%d ",i);
    }
    printf("\n");

    printf("Segment size:\n");
    for (int i=1;i<=8;i++) {
        printf("%d ",siz[i]);
    }
    printf("\n");

    printf("Segment ids:\n");
    for (int i=1;i<=8;i++) {
        printf("%d ",sid[i]);
    }
    printf("\n");
    return 0;
}

void unionfind(int p, int q) {
    if (!isConnected(p,q)) {
        int sidp = find(p);
        int sidq = find(q);
        if (siz[sidp] < siz[sidq]) {
            sid[sidp] = sid[sidq];
            siz[sidq] += siz[sidp];     
        } else {
            sid[sidq] = sid[sidp];
            siz[sidp] += siz[sidq];
        }
        segment_count--;
    }
}

int find(int p) {
    while (p != sid[p]) {
        p = sid[p];
    }
    return p;
}

int isConnected(int p, int q) {
    return (sid[p] == sid[q]); 
}

