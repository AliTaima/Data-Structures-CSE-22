
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


