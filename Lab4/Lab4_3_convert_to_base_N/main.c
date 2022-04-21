#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_to_base(int x, int base)
{

    static char result[40] ;//I make it static to save a memory, as it doesn't work correctly
    if(x <= 0)  //the base condition of recursion
        return "";
    else
    {
        if(x%base >= 10) //check if the number > 10 to convert it to character in case of hexa
        {
            char a =(char)(x%base -10 +'A'); //convert the number >=10to a character
            strncat(result, &a, 1);  //concatenate the new digit with the main string
            convert_to_base(x/base, base);  // call the fun again with new x
        }
        else
        {
            char b =(char)(x%base +'0');//convert the number <10to a character
            strncat(result, &b, 1);//concatenate the new digit with the main string
            convert_to_base(x/base, base);// call the fun again with new x
        }
    }
    revString(result);  //reverse the string as the output reversed
    printf("%s", result) ;
    exit(0);
}

void revString(char *str)
{
    /*
    This function revers the input sting
    */
    int length, a, b;
    char *first, *last, temp;  //declare the *first pointer that point at first character in string
    //and *last that point at last character in string
    //temp to move the character from first to last
    length = strlen (str);  //take the length of the string
    //assign first and last pointer to the first character in string
    first = str;
    last = str;

    for (a = 0; a < length - 1; a++)
        last++;  //to get the index of last char  in sting

    for (b = 0;b < length/2; b++)
    {
        //move the value of last char to first char and vice versa
        temp = *last;
        *last = *first;
        *first = temp;
        //increment and decrement first and last pointer to change the char that point to it
        first++;
        last--;
    }
}

int main()
{
    int X, N;
    scanf("%d%d",&X, &N);
    convert_to_base(X, N);
	return 0;
}


