#include <stdio.h>
#include <stdlib.h>

int main()
{
     float week_gross, Employee_salary;
     printf("Enter Employee gross sale (-1 to end) : ");
     scanf("%f", &week_gross);
    int  ranges[9] = {0};  //This array store the counts of each range and I initialize it with zeros
    int count = 0;  // Count number of employees
    while(week_gross != -1)
    {
        Employee_salary = 200 + .09 * week_gross;
        printf("Employee salary is $%.0f \n", Employee_salary);
        //check the range of salary
        if(200.0 <=Employee_salary && Employee_salary <=290.0)
            ranges[0] += 1;
        else if( 300.0<=Employee_salary  && Employee_salary <= 399.0)
            ranges[1] += 1;
        else if(400.0 <=Employee_salary  && Employee_salary <= 499.0)
            ranges[2] += 1;
        else if(500.0 <=Employee_salary && Employee_salary <= 599.0)
            ranges[3] += 1;
        else if(600.0 <=Employee_salary && Employee_salary <= 699.0)
            ranges[4] += 1;
        else if(700.0 <=Employee_salary && Employee_salary <= 799.0)
            ranges[5] += 1;
        else if(800.0 <=Employee_salary && Employee_salary <= 899.0)
            ranges[6] += 1;
        else if(900 <=Employee_salary && Employee_salary <= 1000)
            ranges[7] += 1;
        else
            ranges[8] += 1;

        count += 1;

        printf("Enter Employee gross sale (-1 to end) : ");
        scanf("%f", &week_gross);

    }
    printf("\n\nTotal %d Employees Reported\n", count);
    printf("Employees in the range:\n");
    int start_range = 200, end_range = 299;  //I make variables to count the ranges unless repeat them
    for(int a = 0; a < 9;a++)
    {
        if(start_range <= 900)
        {
            printf("%d  %d: %d \n", start_range, end_range, ranges[a]);
            //increase range by 100
            start_range += 100;
            end_range += 100;
        }
        else
            printf("over 1000: %d \n", ranges[a]);


    }
    return 0;
}
