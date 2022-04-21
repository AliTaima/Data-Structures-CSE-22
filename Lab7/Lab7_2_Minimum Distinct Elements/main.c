#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int left, int mid, int right)
{
    //this function used for merging each two halves of array and sub-arrays
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int L[leftSize], R[rightSize];
    int i, j, k;
    for (i = 0; i < leftSize; i++)
        L[i] = arr[left + i];
    for (j = 0; j < rightSize; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;  // Initial index of first sub-array
     j = 0;  // Initial index of second sub-array
     k = left;  // Initial index of merged sub-array
    while (i < leftSize && j < rightSize)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //pick up the remaining elements and put in A[left] and A[right]
    while (i < leftSize)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < rightSize)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);  //first half
        mergeSort(arr, mid + 1, right);  //second half

        merge(arr, left, mid, right);
    }
}
int calcFreq(int arr[],int freq[], int size)
{
    /*
        This function calculate the number of repetitions of each element in array and store it in a new array (freq array)
        Then sort this array with Quick sort algorithm then return the new position of the new array according to the number of elements
        and their repetitions
    */
    int pose=0, a;
    int comp = arr[0], count = 1;
    for (a = 1; a< size; a++)
    {
        if(comp == arr[a])
            count ++;

        else
        {
            freq[pose] = count;
            pose ++;
            comp = arr[a];
            count = 1;
        }
    }
    //store the last element
    freq[pose] = count;
    pose ++;
    //sort the array
    mergeSort(freq, 0, pose - 1);

    return pose;
}

int  minDistinct(int arr[], int size, int r)
{
    /*
        This function return the number of minimum distinct
    */
    int index = 0;
    while(r)
    {
        if(r >= arr[index])
        {
            r -= arr[index];
            index ++;
        }
        else
        {
            arr[index] -= r;
            r =0;
        }
    }
    int minDistinct;
    minDistinct = size - index;
    return minDistinct;
}
int main()
{
    int  N, j, r;
    scanf("%d %d", &N, &r);
    int nums[N];
    int freq_arr[N]; // to store number of repetitions of each element

    for (j = 0; j < N; j++)
        scanf("%d", &nums[j]);
    //sort the entered array
    mergeSort(nums, 0, N - 1);
    int freqSize;
    freqSize = calcFreq(nums, freq_arr, N);
    //print the final minimum distinct
    printf("%d", minDistinct(freq_arr, freqSize, r));

    return 0;
}
