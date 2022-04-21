#include <stdio.h>
#include <stdlib.h>

int countDigits(int n, int *f)
{
    /*
        This function count the total number of digits of the number
    */
    int count = 0;
    if(n <= 9)
        *f = n;
    while (n != 0)
    {
        n = n / 10;
        if(n > 0)
            *f = n;
        ++count;
    }
    return count;
}
int getDigit(int n, int d_order, int digits)
{
    /*
        this function get the digit value of the number as user order
    */

    int n_0 = digits - d_order;  //calculate number that should divide by it (multiplies of 10)
    int digit;
    switch(n_0)
    {
    case 0:
        digit = n % 10;
        break;
    case 1:
        n /= 10;
        digit = n % 10;
        break;
    case 2:
        n /= 100;
        digit = n % 10;
        break;
    case 3:
        n /= 1000;
        digit = n % 10;
        break;
    case 4:
        n /= 10000;
        digit = n % 10;
        break;
    case 5:
        n /= 100000;
        digit = n % 10;
        break;
    case 6:
        n /= 100000;
        digit = n % 10;
        break;
    case 7:
        n /= 10000000;
        digit = n % 10;
        break;
    case 8:
        n /= 100000000;
        digit = n % 10;
        break;
    case 9:
        n /= 1000000000;
        digit = n % 10;
        break;
    default:
        return 0;
    }
    return digit;
}
int greater(int num1, int num2)
{
    /*
        this function check if the num1 is greater than num2 or not but according to the digits of the number
        for example if the two numbers are 9 and 1234, so the 9 is the greater because it has high digit and so on
    */
    if(num1 <= 9 && num2 <= 9) //simple check if the number is 1 digit
    {
        if(num1 > num2)
            return 1;
        else
            return 0;
    }
    else
    {
        int digits1, f1=0; //digits and first digit for num1
        int digits2, f2=0; //digits and first digit for num2
        digits1 = countDigits(num1, &f1);
        digits2 = countDigits(num2, &f2);
        //check first digit in each number before other digits
        if(f1 > f2)
            return 1;
        else if(f1 < f2)
            return 0;
        else
        {
            int a;
            for (a = 2; a <= 9; a++)
            {
                if(a <= digits1 && a <= digits2)
                {

                    if(getDigit(num1, a, digits1) > getDigit(num2, a, digits2))
                        return 1;
                    else if(getDigit(num1, a, digits1) < getDigit(num2, a, digits2))
                        return 0;
                    else
                        continue;
                }
                else
                {
                    if(digits1 > digits2)
                    {
                        if(getDigit(num1, a, digits1) > getDigit(num2, a - 1, digits2))
                           return 1;
                       else
                            return 0;

                    }
                    else
                        return 0;
                }
            }
        }
    }
exit(0);
}
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int partition (int arr[], int low, int high)
{
    /* This function takes last element as pivot, places the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
     */

    int pivot = arr[high]; // suppose the pivot is the last element in the array
    int a = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    int b;
    for (b = low; (b == high - 1) || greater(high - 1, b) ; b++)
    {
        // If  the pivot is greater than current element
        if (greater(pivot, arr[b]))
        {
            a++;
            swap(&arr[a], &arr[b]);
        }
    }
    swap(&arr[a + 1], &arr[high]);
    return (a + 1);
}

void quickSort(int arr[], int low, int high)
{
    /*
        This function sort elements before and after the partition index and all elements sorted at the end
    */
    if (greater(high, low))
    {

        int pi = partition(arr, low, high);  // the partition index

        //sort elements before and after the partition index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{

    int N;
    scanf("%d", &N);

    int arr[N], a;

    for(a = 0; a<N; a++)
        scanf("%d", &arr[a]);

    quickSort(arr, 0, N - 1);

    for(a = N - 1; a>=0; a--)
        printf("%d", arr[a]);


    return 0;
}
