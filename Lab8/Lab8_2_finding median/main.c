#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int arr[], int n, int index)
{

    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Find largest among root, left child and right child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != index)
    {
        swap(&arr[index], &arr[largest]);

        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
    // Build max heap
    int a;
    for (a = n / 2 - 1; a >= 0; a--)
        heapify(arr, n, a);

    // Heap sort
    for (a = n - 1; a > 0; a--) {
        // Move current root to end
        swap(&arr[0], &arr[a]);

        //Get highest element at root again
        heapify(arr, a, 0);
    }
}
float getMedian(int arr[], int size)
{
    float median;
    if(size % 2 == 0)
    {
        median = (float)(arr[(size / 2) - 1] + arr[size / 2]) / 2.0;
    }
    else
    {
        median = arr[size/2];
    }
    return median;
}


int main()
{
    int N;
    scanf("%d", &N);

    int arr[N], a;

    for(a = 0; a<N; a++)
        scanf("%d", &arr[a]);

    heapSort(arr, N);

    float median;
    if(N == 0)
        printf("Not Exist");
    else
    {
        median = getMedian(arr, N);
        if(median == (int)median)
            printf("%d", (int)median);
        else
            printf("%.1f", median);
    }

    return 0;
}
