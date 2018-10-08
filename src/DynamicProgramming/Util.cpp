#include "Util.h"
#include <cstring>

int *ArrayNew(int n) {
  int *f = new int[n];
  return f;
}

void ArrayFree(int *f) { delete[] f; }

int **Array2DNew(int n, int m) {
  int **f = new int *[n];
  for (int i = 0; i < n; i++) {
    f[i] = new int[m];
  }
  return f;
}

void Array2DFree(int **f, int n) {
  for (int i = 0; i < n; i++) {
    delete[] f[i];
  }
  delete[] f;
}

int ***Array3DNew(int n, int m, int t) {
  int ***f = new int **[n];
  for (int i = 0; i < n; i++) {
    f[i] = new int *[m];
    for (int j = 0; j < m; j++) {
      f[i][j] = new int[t];
    }
  }
  return f;
}

void Array3DFree(int ***f, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      delete[] f[i][j];
    }
    delete[] f[i];
  }
  delete[] f;
}

