#include <stdio.h>
#include <stdlib.h>
void scan_arr(int arr[], int size);
void order_arr(int arr[], int size);
int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    int h[N];
    int t[Q];
    scan_arr(h, N);//take the inputs from the first array
    scan_arr(t, Q);  //take the inputs from the second array
    order_arr(h, N);  //order the first array
    order_arr(t, Q);  //order the second array
    int count = 0, dev_pose = 0;
    /*count --> to count the number of developers that take tasks
        dev_pose --> to initialize each loop in developers array with the next developer (not start from
        the beginning because each developer in the beginning take a task or his time not enough to take a task*/

    for(int x = 0; x<Q;x++)
    {
        for (int y = dev_pose;y<N;y++)
        {
            dev_pose += 1;  //move to the next developer
            if(t[x] <= h[y])
            {
                count += 1;  //count developer that take tasks by 1
                break;  //break, as i found the developer that take the task

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
    for (int a = 0;a<size;a++)
    {
        scanf("%d", &arr[a]);
    }

}
void order_arr(int arr[], int size)
{
    int temp;
    for (int i = 0; i<size;i++)
    {
        int change = 0;
        for(int j = 0;j<size;j++)
        {
            if(arr[j+1]<arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                change = 1;
            }
        }
        if (change == 0)
            break;
    }
}


