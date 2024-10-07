int** MakeSpiral(int n) {
  int** matr = new int*[n];
  for (int i = 0; i < n; i++) {
    matr[i] = new int[n];
  }
  int k = n - 1;
  int s = 0;
  int m = 0;
  while (m < n * n) {
    for (int i = s; i < k; i++) {
      matr[s][i] = ++m;
    }
    for (int i = s; i < k; i++) {
      matr[i][k] = ++m;
    }
    for (int i = k; i > s; i--) {
      matr[k][i] = ++m;
    }
    for (int i = k; i > s; i--) {
      matr[i][s] = ++m;
    }
    k--;
    s++;
    if (k == s) {
      matr[k][s] = ++m;
    }
  }
  return matr;
}
