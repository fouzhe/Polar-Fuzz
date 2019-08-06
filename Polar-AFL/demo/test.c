#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 0;
    }

    FILE *file = NULL;

    file = fopen(argv[1], "rb");
    if(file == NULL)
    {
        printf("Fail to open file!");
        return 0;
    }
    
    __POLAR_INS((1<<16));  // Polar Instrumentation
    
    fread(buf, sizeof(char), 8, file);
    
    return 0;
}
