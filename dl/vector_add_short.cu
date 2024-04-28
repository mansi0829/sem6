%%cu
#include<iostream>
using namespace std; 

__global__ void add(int * a, int* b , int *c, int size)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if(i < size){
        c[i] = b[i]+a[i];
    }
}

__managed__ int vector_a[256], vector_b[256], vector_c[256];


int main()
{
    for(int i=0;i<256;i++)
    {
        vector_a[i] = i;
        vector_b[i] = 256-i;

    }
    add<<<1,256>>>(vector_a,vector_b,vector_c,256);
    cudaDeviceSynchronize();

    for(int i=0;i<256;i++)
    {
        cout<<vector_c[i]<<" ";
    }
 return 0;
}
