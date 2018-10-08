#pragma once

int *ArrayNew(int n);

void ArrayFree(int *f);

int **Array2DNew(int n, int m);

void Array2DFree(int **f, int n);

int ***Array3DNew(int n, int m, int t);

void Array3DFree(int ***f, int n, int m);

