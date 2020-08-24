// hack for descending sort
void negateArray(int A[], int n) {
  for (int i=0; i<n; ++i){
    A[i] *= -1;
  }
}

// heapify A[i] in the heap
void maxHeapify(int A[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && A[l] > A[largest])
    largest = l;
  if (r < n && A[r] > A[largest])
    largest = r;
  if (largest != i) {
    std::swap(A[i], A[largest]);
    maxHeapify(A, n, largest);
  }
}

// convert array into heap
void buildMaxHeap(int A[], int n) {
  for (int i = n/2-1; i >= 0; i--) {
    maxHeapify(A, n, i);
  }
}

// sort elements in Ascending order
void heapsortAsc(int A[], int n) {
  buildMaxHeap(A, n);
  for (int i = n - 1; i > 0; i--) {
    std::swap(A[0], A[i]);
    maxHeapify(A, i, 0);
  }
}

// sort elements in Descending order
void heapsortDesc(int A[], int n) {
  negateArray(A, n);
  heapsortAsc(A, n);
  negateArray(A, n);
}
