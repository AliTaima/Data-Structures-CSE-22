#include <stdio.h>
#include <stdlib.h>
void matrix_input(int mat[3][3]);  //Declaration of matrix input function
int main()
{
    //Declaration of three matrices
    int matrix1[3][3], matrix2[3][3], matrix3[3][3];
    printf("Enter the elements of matrix1 size(3*3): \n");  //ask the user to enter the elements of matrix1
    matrix_input(matrix1);
    printf("Enter the elements of matrix2 size(3*3): \n");//ask the user to enter the elements of matrix2
    matrix_input(matrix2);
    printf("\n \nSum of both matrices: \n");
    for(int a = 0; a<3;a++)
    {
        for(int b = 0; b<3; b++)
        {
            *(*(matrix3+a)+b) = *(*(matrix1+a)+b) + *(*(matrix2+a)+b);
            printf("%d  ", *(*(matrix3+a)+b));
        }
        printf("\n");
    }

    return 0;
}
/*
This function ask the user to enter the elements of matrix size(3*3)
*/
void matrix_input(int mat[3][3])
{
    for(int a = 0; a<3;a++)
    {
        for(int b = 0; b<3; b++)
        {
            scanf("%d", (*(mat+a)+ b));
        }
    }
}
