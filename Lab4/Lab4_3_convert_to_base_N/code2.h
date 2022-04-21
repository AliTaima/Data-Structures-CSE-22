/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
result [100];
const char* convert_to_base(int x, int base)
{

    if(x <= 0)
        return 0;
    else
    {
        return sprintf(result, "%s%d", result, x%base,convert_to_base(x/10, base));
    }

}
convert_to_string(char input[])
{

}
int main()
{
    int x = 13, base = 2;
    printf("%s", convert_to_base(x, base));
	return 0;
}

-----------------------
int convert_to_base(int x, int base)
{
    if(x <= 0)
        return 0;
    else
    {
        return ( x%base+10*convert_to_base(x/base, base));
    }

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* convert_to_base(int x, int base)
{
    static char result[40];  //I make it
    if(x <= 0)
        return "";
    else
    {
        if(x%base >= 10)
        {
            int a = x%base + 55;
            sprintf(result,"%s%c", result, a);
            convert_to_base(x/base, base);
        }
        else
        {
            sprintf(result,"%s%d", result, x%base);
            convert_to_base(x/base, base);
        }

        return result;
    }
}


int main()
{
    int X, N;
    scanf("%d%d",&X, &N);
    char *a;
    a = convert_to_base(X, N);
    strrev(a);
    printf("%s", a);
	return 0;
}



*/

