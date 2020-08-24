#include <string>
#include <iostream>
using namespace std;

class Heap {
    private:

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

        void buildMaxHeap(int A[], int n) {
            for (int i = n/2-1; i >= 0; i--) {
                maxHeapify(A, n, i);
            }
        }

        void heapsort( int A[], int n ) {
            buildMaxHeap(A, n);
            for (int i = n - 1; i > 0; i--) {
                std::swap(A[0], A[i]);
                maxHeapify(A, i, 0);
            }
        }

    public:
        void heapsort( int A[] ) {
           // int n = sizeof(*A)/sizeof(A[0]);
           int n = 11;
           heapsort( A, n );
        }
};

int main(void) {
    int A[] = {3,4,56,39,294,5,493,81,3,4,38};
    Heap h;
    h.heapsort(A);

    for (auto i: A) {
        cout << i << endl;
    }

    return 0;
}
