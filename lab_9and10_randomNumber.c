#include <stdio.h>

#define SEQUENCE_LENGTH 10

void generateSequence(int modulus, int a, int c, int isMixed);

int main()
{
    int choice;
    int modulus;
    int a = 3;
    int c = 2;

    printf("Choose the method to generate random numbers:\n");
    printf("1. Mixed Congruential Method\n");
    printf("2. Multiplicative Congruential Method\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter the modulus value: ");
    scanf("%d", &modulus);

    switch (choice)
    {
    case 1:
        generateSequence(modulus, a, c, 1);
        break;
    case 2:
        generateSequence(modulus, a, c, 0);
        break;
    default:
        printf("Invalid choice. Please run the program again and choose a valid option.\n");
    }

    return 0;
}

void generateSequence(int modulus, int a, int c, int isMixed)
{
    int x = 4;
    int randomNumbers[SEQUENCE_LENGTH];
    double randomVariables[SEQUENCE_LENGTH];

    // Generate the sequence using the specified congruential method
    for (int i = 0; i < SEQUENCE_LENGTH; i++)
    {
        if (isMixed)
        {
            x = (a * x + c) % modulus;
        }
        else
        {
            x = (a * x + c) % modulus;
        }
        randomNumbers[i] = x;
        randomVariables[i] = (double)x / modulus;
    }

    // Print the generated sequence of random numbers
    printf("Sequence of %d random integers (%s Congruential Method):\n", SEQUENCE_LENGTH, isMixed ? "Mixed" : "Multiplicative");
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
}
