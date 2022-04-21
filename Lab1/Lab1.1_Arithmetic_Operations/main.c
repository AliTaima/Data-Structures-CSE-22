#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n;  //Store the values of five numbers
    float sum_p = 0, sum_n = 0;  //sum the positive and negative numbers
    int count_n = 0, count_p = 0; //counter for positive and negative numbers
    printf("Enter five floating numbers:\n");
    for(int a = 0; a<5; a++)
    {
        scanf("%f", &n);
        if(n < 0)
        {
           sum_n += n;
           count_n += 1;
        }
        else if(n > 0)
        {
            sum_p += n;
            count_p += 1;
        }
    }
    printf("\n\nNumber of positive numbers: %d\n", count_p);
    printf("Number of negative numbers: %d\n", count_n);
    printf("Average of positive numbers: %.2f\n", sum_p/count_p);
    printf("Average of negative numbers: %.2f", sum_n/count_n);
    return 0;
}
