#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototype
double chi_square_test(double observed[], double expected[], int n);

int main()
{
    int n;

    printf("Enter the number of categories: ");
    scanf("%d", &n);

    double observed[n];
    double expected[n];

    printf("Enter the observed frequencies:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &observed[i]);
    }

    printf("Enter the expected frequencies:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &expected[i]);
    }

    double chi_square_statistic = chi_square_test(observed, expected, n);
    printf("Chi-square statistic: %.5f\n", chi_square_statistic);

    // Here, you would compare the chi-square statistic with critical values or use a p-value
    // For simplicity, we omit the critical value comparison and p-value calculation

    return 0;
}

// Chi-square test function
double chi_square_test(double observed[], double expected[], int n)
{
    double chi_square = 0.0;

    for (int i = 0; i < n; i++)
    {
        chi_square += pow(observed[i] - expected[i], 2) / expected[i];
    }

    return chi_square;
}
