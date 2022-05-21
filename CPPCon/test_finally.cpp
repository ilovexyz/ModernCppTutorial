#include "Finally.h"
#include <iostream>

int main()
{
    FILE *fp = fopen("Finally.h", "r");
    if (!fp)
    {
        printf("Open failed...\n");
        return 0;
    }
    CFinally f_close([&]
                     { 
                        printf("closing fp...\n");
                        fclose(fp); });

    FINALLY([&]
            {
                printf("closing fp...\n");
                fclose(fp); });
    return 0;
}
