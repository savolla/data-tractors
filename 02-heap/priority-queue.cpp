
int poll(int A[], int &n) {
  if (n < 1) {
    cout << "heap underflow!";
    return -1;
  }
  int max = A[0];
  A[0] = A[n - 1];
  n--;
  maxHeapify(A, n, 0);
  return max;
}
