#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHOWPASS

void print(int *a, int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
}

void radixsort(int *a, int n) {
  int i, m = a[0], exp = 1;
  const int base = 10;
  int *b = (int*) malloc(n * sizeof(int));
  int *bucket = (int*) calloc(base, sizeof(int));

  //Get the greatest value in the array a and assign it to m
  for (i = 1; i < n; i++) {
    if (a[i] > m)
      m = a[i];
  }

  //Loop until exp is bigger than the largest number
  while (m / exp > 0) {
    memset(bucket, 0, base * sizeof(int));

    //Count the number of keys that will go into each bucket
    for (i = 0; i < n; i++) {
      bucket[(a[i] / exp) % base]++;
    }

    //Add the count of the previous buckets to acquire the indexes after the end of each bucket location in the array
    for (i = 1; i < base; i++) {
      bucket[i] += bucket[i - 1]; //similar to count sort algorithm i.e. c[i]=c[i]+c[i-1];
    }

    //Starting at the end of the list, get the index corresponding to the a[i]'s key, decrement it, and use it to place a[i] into array b.
    for (i = n - 1; i >= 0; i--) {
      b[--bucket[(a[i] / exp) % base]] = a[i];
    }

    //Copy array b to array a
    for (i = 0; i < n; i++) {
      a[i] = b[i];
    }

    //Multiply exp by the BASE to get the next group of keys
    exp *= base;

    #ifdef SHOWPASS
      printf("\nPASS   : ");
      print(a, n);
    #endif
  }

  free(bucket);
  free(b);
}

int main() {
  int i, n;
  printf("Enter total elements: ");
  scanf("%d", &n);
  int *arr = (int*) malloc(n * sizeof(int));

  printf("Enter %d Elements: ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nARRAY  : ");
  print(arr, n);

  radixsort(arr, n);

  printf("\nSORTED : ");
  print(&arr[0], n);
  printf("\n");

  return 0;
}