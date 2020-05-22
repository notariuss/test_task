#include "stdlib.h"
#include <stdio.h>

int calculate(int N, int K)
{
    int result;
    int current;

    result = 0;
    current = 0;
    while (current <= N)
    {
        current = current + K + 1;
        result = result + 1;
    }
    return result;
}

int main(int argc, char **argv)
{
    int N;
    int K;

    if (argc != 3)
    {
        return(1);
    }
    N = atoi(argv[1]);
    K = atoi(argv[2]);
    printf("%d\n", calculate(N, K));
    return(0);
}
