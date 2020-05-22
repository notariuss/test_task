#include <stdlib.h>
#include <stdio.h>

int calculate(int N, int D)
{
    int result;

    result = 0;
    while (N != 0)
    {
        result = result + (N * D);
        N = N - 1;
    }
    return (result);
}


int main(int argc, char **argv)
{
    if (argc != 3)
    {
        return (1);
    }

    printf("%d\n", calculate(atoi(argv[1]), atoi(argv[2])));
    return (0);
}
