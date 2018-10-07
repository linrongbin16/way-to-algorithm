#include "Util.h"
#include <cstring>

int **Array2DNew(int n, int m) {
  int **a = new int *[n];
  for (int i = 0; i < n; i++) {
    a[i] = new int[m];
  }
  return a;
}

void Array2DFree(int **a, int n) {
  for (int i = 0; i < n; i++) {
    delete[] a[i];
  }
  delete[] a;
}

int ***Array3DNew(int n, int m, int t) {
  int ***a = new int **[n];
  for (int i = 0; i < n; i++) {
    a[i] = new int *[m];
    for (int j = 0; j < m; j++) {
      a[i][j] = new int[t];
    }
  }
  return a;
}

void Array3DFree(int ***a, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      delete[] a[i][j];
    }
    delete[] a[i];
  }
  delete[] a;
}

