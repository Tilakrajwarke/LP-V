#include <iostream>
#include <cuda_runtime.h>
using namespace std;

__global__ void vectorAdd(int *A, int *B, int *C, int n) {
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < n)
        C[i] = A[i] + B[i];
}

int main() {
    int n;
    cout << "Enter size of vectors: ";
    cin >> n;

    int A[n], B[n], C[n];
    int *d_A, *d_B, *d_C;

    cout << "Enter elements of A:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter elements of B:\n";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    cudaMalloc((void**)&d_A, n * sizeof(int));
    cudaMalloc((void**)&d_B, n * sizeof(int));
    cudaMalloc((void**)&d_C, n * sizeof(int));

    cudaMemcpy(d_A, A, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, n * sizeof(int), cudaMemcpyHostToDevice);

    int blockSize = 256;
    int gridSize = (n + blockSize - 1) / blockSize;

    vectorAdd<<<gridSize, blockSize>>>(d_A, d_B, d_C, n);

    cudaMemcpy(C, d_C, n * sizeof(int), cudaMemcpyDeviceToHost);

    cout << "Resultant vector:\n";
    for (int i = 0; i < n; i++)
        cout << C[i] << " ";
    cout << endl;

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
