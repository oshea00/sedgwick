/*
 * euclid.c
 *
 * Euclidean algorithm for computing the greatest common divisor (GCD)
 * of two non-negative integers.
 *
 * From Robert Sedgewick, "Algorithms in C" (1990), Ch. 1, Program 1.1.
 *
 * The algorithm repeatedly subtracts the smaller number from the larger
 * until one of them reaches zero; the remaining nonzero value is the GCD.
 * This is the subtraction-based form Sedgewick presented (as opposed to
 * the modern remainder-based form using '%').
 */
#include <stdio.h>

int gcd(int, int);

int gcd(int u, int v) {
  int t;
  do {
    // Ensure u is the larger of the two.
    if (u < v) {
      t = u;
      u = v;
      v = t;
    }
    // Subtract the smaller (v) from the larger (u).
    /* printf("u = %d, v = %d\n",u,v); */
    u = u - v;
    // Repeat until u reaches 0; v then holds the GCD.
  } while (u > 0);
  return v;
}

int main(void) {
  int u, v;
  printf("max int = %d", __INT_MAX__);
  // Loop reading pairs of non-negative inputs; a negative value exits.
  while (1) {
    printf("enter u v: ");
    scanf("%d %d", &u, &v);
    if (u < 0 || v < 0)
      break;
    printf("u=%d v=%d gcd=%d\n", u, v, gcd(u, v));
  }
}
