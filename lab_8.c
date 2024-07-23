// m=100,a=19,c=0 and x0 =63 and generate a sequence random integer.write a program to find first 7 random number generate using any suitable method in c program

#include <stdio.h>

// Parameters for LCG
int m = 100;
int a = 19;
int c = 0;

// Initial seed
int x0 = 63;

// Function to generate next pseudo-random number
int lcg_rand(int *seed)
{
    *seed = (a * (*seed) + c) % m;
    return *seed;
}

int main()
{
    int i;
    int rand_num;

    // Generate and print the first 7 random numbers
    printf("First 7 random numbers:\n");
    for (i = 0; i < 7; i++)
    {
        rand_num = lcg_rand(&x0);
        printf("%d\n", rand_num);
    }

    return 0;
}
