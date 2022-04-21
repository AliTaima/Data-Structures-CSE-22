#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
void shellSort(int arr[], int n)
{
    int g, a, b, temp;
    for (g = n / 2; g > 0; g /= 2) // the gap that use and reduce it each iteration by division by 2
    {
        for (a = g; a < n; a++) // the last element in the gap
        {
            temp = arr[a]; // save the element that will compare

            for (b = a; b >= g && arr[b - g] > temp; b -= g) // compare first and last element in the gap
                arr[b] = arr[b - g];

            arr[b] = temp; // put the element that saved in its right position
        }
        // printf("\nthe gap = %d\n", g);
        // printArray(arr, n);
    }
}

void insertArray(int arr[], int n)
{
    int a;
    for (a = 0; a < n; a++)
        scanf("%d", &arr[a]);
}
int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    int nums[N];
    insertArray(nums, N);
    shellSort(nums, N);
    printf("%d", nums[N - K]);
    return 0;
}
