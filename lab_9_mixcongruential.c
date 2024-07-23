#include <stdio.h>

#define SEQUENCE_LENGTH 10
#define MODULUS 100000

int main()
{
    int a = 3;
    int c = 2;
    int x = 4;
    int randomNumbers[SEQUENCE_LENGTH];
    double randomVariables[SEQUENCE_LENGTH];

    // Generate the sequence using the mixed congruential method
    for (int i = 0; i < SEQUENCE_LENGTH; i++)
    {
        x = (a * x + c) % MODULUS;
        randomNumbers[i] = x;
        randomVariables[i] = (double)x / MODULUS;
    }

    // Print the generated sequence of random numbers
    printf("Sequence of %d five-digit random integers:\n", SEQUENCE_LENGTH);
    for (int i = 0; i < SEQUENCE_LENGTH; i++)
    {
        printf("%d ", randomNumbers[i]);
    }
    printf("\n");

    // Print the corresponding random variables
    printf("Corresponding random variables:\n");
    for (int i = 0; i < SEQUENCE_LENGTH; i++)
    {
        printf("%.5f ", randomVariables[i]);
    }
    printf("\n");

    return 0;
}
