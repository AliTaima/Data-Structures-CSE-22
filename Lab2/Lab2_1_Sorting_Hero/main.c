#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    int h[N];
    int t[Q];

    scan_arr(h, N);
    scan_arr(t, Q);
    sort_arr(h, N);
    sort_arr(t, Q);

    int count = 0, dev_pose = 0;
    /*count --> to count the number of developers that take tasks
        dev_pose --> to initialize each loop in developers array with the next developer (not start from
        the beginning because each developer in the beginning take a task or his time not enough to take a task*/

    int x, y;
    for( x = 0; x<Q;x++)
    {
        for ( y = dev_pose;y<N;y++)
        {
            dev_pose += 1;  //move to the next developer
            if(t[x] <= h[y])
            {
                count += 1;  //count developer that take tasks by 1
                break;  //break, as i found the developer that take the tas
            }
        }
        if (dev_pose == N)  //check if all developers take tasks or not, if they take but there are more tasks
            break;  // I will break because I don't have enough developers for tasks
    }

    printf("%d", count);



    return 0;
}
void scan_arr(int arr[], int size)
{
    int a;
    for (a= 0;a<size;a++)
    {
        scanf("%d", &arr[a]);
    }
}
void sort_arr(int arr[], int size)
{
    int temp, i, j, min;
    for ( i = 0; i<size;i++)
    {
        min = arr[i];
        for( j = 0;j<size;j++)
        {
            if(arr[i] < min)
            {
                temp = min;
                min = arr[j];
                arr[j] = temp;
            }
        }
        arr[i] = min;
    }
}

